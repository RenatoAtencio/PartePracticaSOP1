#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <filesystem>
#include <unordered_map>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

// Definición de las variables de entorno
const string EXTENSION = "txt";
const string PATH_FILES_IN = "Input";
const string PATH_FILES_OUT = "Output";
const int AMOUNT_THREADS = 4;

mutex mtx;//evito que hilos multiples accedan al mismo archivo
condition_variable cv;
queue<string> filesToProcess;
bool done = false;

// Función para procesar un archivo de texto y contar palabras
void processFile(int threadId) {
    while (true) {
        string filePath;
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [] { return !filesToProcess.empty() || done; });
            if (filesToProcess.empty() && done) {
                break;
            }
            filePath = filesToProcess.front();
            filesToProcess.pop();
        }

        ifstream inputFile(filePath);
        if (!inputFile) {
            cerr << "Error al abrir el archivo: " << filePath << endl;
            return;
        }
        unordered_map<string, int> wordCount;
        string word;
        while (inputFile >> word) {
            // Limpia la palabra de caracteres no alfabéticos
            word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());

            if (!word.empty()) {
                transform(word.begin(), word.end(), word.begin(), ::tolower); // Convertir a minúsculas
                wordCount[word]++;
            }
        }
        inputFile.close();

        string fileName = filePath.substr(filePath.find_last_of('/') + 1);
        string outputPath = PATH_FILES_OUT + "/" + fileName;
    

        ofstream outputFile(outputPath);
        if (!outputFile.is_open()) {
            cerr << "No se pudo crear el archivo de salida." << endl;
            return;
        }

        for (const auto& entry : wordCount) {
            outputFile << entry.first << ";" << entry.second << endl;
        }
        outputFile.close();

        mtx.lock();
        cout << "Archivo " << filePath << ", procesado por el thread " << threadId << endl;
        mtx.unlock();         
    }
}

// Función para procesar archivos en paralelo
void processFilesInParallel() {
    vector<thread> threads;

    for (int i = 0; i < AMOUNT_THREADS; i++) {
        threads.emplace_back(processFile, i);
    }

    for (const auto& entry : fs::directory_iterator(PATH_FILES_IN)) {
        if (entry.is_regular_file() && entry.path().extension() == "." + EXTENSION) {
            string filePath = entry.path().string();
            {
                lock_guard<mutex> lock(mtx);
                filesToProcess.push(filePath);
            }
            cv.notify_one();
        }
    }

    {
        lock_guard<mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();

    for (thread& t : threads) {
        t.join();
    }
}

int main() {
    processFilesInParallel();
    return 0;
}

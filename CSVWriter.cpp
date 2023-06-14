#include "CSVWriter.h"

CSVWriter::CSVWriter(const std::string& filename) {
    outputFile.open(filename);
}

CSVWriter::~CSVWriter() {
    outputFile.close();
}

void CSVWriter::writeRow(const std::vector<std::string>& row) {
    for (size_t i = 0; i < row.size(); i++) {
        outputFile << row[i];
        if (i != row.size() - 1) {
            outputFile << ",";
        }
    }
    outputFile << "\n";
}

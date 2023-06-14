#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <fstream>
#include <vector>
#include <string>

class CSVWriter {
    std::ofstream outputFile;

public:
    CSVWriter(const std::string& filename);

    ~CSVWriter();

    void writeRow(const std::vector<std::string>& row);
};

#endif  // CSVWRITER_H

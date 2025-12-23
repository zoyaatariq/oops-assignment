

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class dofile {
    fstream file;
    string fname;

public:
    class FileError {
        string msg;
    public:
        FileError(const string& m) : msg(m) {}
        string what() const { return msg; }
    };

    dofile(const string& filename) : fname(filename) {
        file.open(fname, ios::in | ios::out | ios::app);
        if (!file) throw FileError("Cannot open file: " + fname);
    }

    void write(const string& data) {
        if (!(file << data)) throw FileError("Write error in file: " + fname);
    }

    string readLine() {
        string line;
        if (!getline(file, line)) throw FileError("Read error or EOF in file: " + fname);
        return line;
    }

    void reset() {
        file.clear();
        file.seekg(0, ios::beg);
        if (!file) throw FileError("Reset failed for file: " + fname);
    }

    ~dofile() { if (file.is_open()) file.close(); }
};

int main() {
    try {
        dofile df("example.txt");
        df.write("Hello, world!\n");
        df.reset();
        cout << "Reading file contents:\n";
        try {
            while (true) {
                cout << df.readLine() << endl;
            }
        } catch (dofile::FileError&) {}
    } catch (dofile::FileError& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

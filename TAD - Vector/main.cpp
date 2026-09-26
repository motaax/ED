#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Vector.h"

using namespace std;

int main() {
    Vector myvec;
    
    while(true) {
        string line;
        string comando;
        
        if (!getline(cin, line)) break;
        if (line.empty() || line[0] == '#') continue; // ignora comentarios
        
        stringstream ss { line };
        ss >> comando;

        if(comando == "exit") {
            cout << "$exit\n";
            return 0;
        }
        else if(comando == "front") {
            cout << "$front\n";
            try {
                cout << myvec.front() << '\n';
                const Vector cvec(myvec);
                cout << "front of const copy vector: " << cvec.front() << '\n';
            } catch (const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
        }
        else if(comando == "back") {
            cout << "$back\n";
            try {
                cout << myvec.back() << '\n';
                const Vector cvec(myvec);
                cout << "back of const copy vector: " << cvec.back() << '\n';
            } catch (const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
        }
        else if(comando == "removeall") {
            int v;
            ss >> v;
            cout << "$removeall " << v << '\n';
            myvec.remove_all(v);
        }
        else if(comando == "insertat") {
            int v, k;
            ss >> v >> k;
            cout << "$insertat " << v << " " << k << '\n';
            try {
                myvec.insert_at(v, k);
            }
            catch(const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
        }
        else if(comando == "removeat") {
            int k;
            ss >> k;
            cout << "$removeat " << k << '\n';
            try {
                myvec.remove_at(k);
            }
            catch(const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
        }
        else if(comando == "pushback") {
            int v;
            cout << "$pushback";
            while(ss >> v) {
                cout << " " << v;
                myvec.push_back(v);
            }
            cout << "\n";
        }
        else if(comando == "print") {
            cout << "$print\n";
            for(size_t i{}; i < myvec.size(); ++i) {
                cout << myvec[i] << (i + 1 == myvec.size() ? "" : " ");
            }
            cout << endl;
        }
        else if(comando == "size") {
            cout << "$size\n";
            cout << myvec.size() << endl;
        }
        else if(!comando.empty()) {
            cout << "comando inexistente" << endl;
        }
    }
    
    return 0;
}
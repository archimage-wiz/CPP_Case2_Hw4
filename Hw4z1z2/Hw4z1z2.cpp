#include <iostream>
#include <string>
#include <fstream>
#include "address.cpp"

void sort(Address ** addr_array, int size){
    bool is_swapped = false;
    do {
        is_swapped = false;
        for (int x_cnt = 0; x_cnt < size-1; ++x_cnt) {
            if ( addr_array[x_cnt]->get_output_address().compare(addr_array[x_cnt+1]->get_output_address()) > 0 ) {
                std::swap(addr_array[x_cnt], addr_array[x_cnt+1]);
                is_swapped = true;
                break;
            }
        }
    } while (is_swapped);
}

int main() { setlocale(LC_ALL, "Ru"); system("chcp 1251");

    std::ifstream in_strm ("in.txt");

    int addr_cnt;
    if (!in_strm.is_open() || !(in_strm >> addr_cnt)) std::exit(-1);
    
    Address ** addr_array = new Address * [addr_cnt];

    for (int x_cnt = 0; x_cnt < addr_cnt; x_cnt++) {
        std::string city, street;
        int house, room;
        in_strm >> city >> street >> house >> room;
        addr_array[x_cnt] = new Address(city, street, house, room);
    }
    in_strm.close();

    sort(addr_array, addr_cnt);

    std::ofstream out_strm ("out.txt");
    if (!out_strm.is_open()) std::exit(-1);
    out_strm << addr_cnt << std::endl;
    for (int x_cnt = 0; x_cnt < addr_cnt; x_cnt++) {
        out_strm << addr_array[x_cnt]->get_output_address() << std::endl;
        std::cout << addr_array[x_cnt]->get_output_address() << std::endl;
    }
    out_strm.close();

    for (int this_addr_cnt = 0; this_addr_cnt < addr_cnt; this_addr_cnt++) {
        delete addr_array[this_addr_cnt];
    }
    delete [] addr_array;

}


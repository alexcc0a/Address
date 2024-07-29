//
//  main.cpp
//  Addresses
//
//  Created by Александр Нестеров on 28/07/2024.
//

#include <iostream>
#include <string>
#include <fstream>

class Address {
public:
    Address() {}
    Address(std::string city, std::string street, int house_number, int apartment_number) {
        this->city = city;
        this->street = street;
        this->house_number = house_number;
        this->apartment_number = apartment_number;
    }
    std::string get_otput_address() {
        return this->city + ", " + this->street + ", " + std::to_string(this->house_number)
        + ", " + std::to_string(this->apartment_number);
    }
private:
    std::string city;
    std::string street;
    int house_number;
    int apartment_number;
};

int main() {
    std::ifstream inFile("in.txt");
    if (inFile.is_open()) {
        int size;
        inFile >> size;
        Address* arr = new Address[size];
        
        for (int i = 0; i < size; ++i) {
            std::string city;
            std::string street;
            int house_number;
            int apartment_number;
            
            inFile >> city;
            inFile >> street;
            inFile >> house_number;
            inFile >> apartment_number;
            
            Address address(city ,street, house_number, apartment_number);
            arr[i] = address;
        }
        std::ofstream outFile("out.txt");
        
        if (outFile.is_open()) {
            outFile << size << std::endl;
            for (int i = size -1; i >= 0; --i) {
                outFile << arr[i].get_otput_address() << std::endl;
            }
            outFile.close();
            inFile.close();
        } else {
            std::cout << "Не удалось открыть файл для записи!" << std::endl;
        }
        delete[] arr;
    } else {
        std::cout << "Не удалось открыть файл для чтения!" << std::endl;
    }
    return 0;
}

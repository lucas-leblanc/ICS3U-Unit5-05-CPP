// Copyright (c) 2022 Lucas LeBlanc All rights reserved

// Created by: Lucas LeBlanc
// Created on: Dec 2022
// This program formats someones address

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

std::string address(std::string fullName,
                    std::string streetNumber,
                    std::string streetName,
                    std::string city,
                    std::string province,
                    std::string postalCode,
                    std::string apartementNumber = "") {
    // return the address properly formatted
    std::string proper;

    proper = fullName + "\n";
    if (apartementNumber != "") {
        proper = proper + apartementNumber + "-";
    }
    proper = proper + streetNumber;
    proper = proper + " " + streetName + "\n";
    proper = proper + city + " ";
    proper = proper + province + "  ";
    proper = proper + postalCode;

    std::for_each(proper.begin(),
                  proper.end(), [](char& c) { c = ::toupper(c); });

    return proper;
}

bool isItaNumber(std::string strOrNum) {
    for (int element = 0; element < strOrNum.length(); element++) {
        if (isdigit(strOrNum[element]) == false) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    // gets a users name and prints out their formal name
    std::string fullName;
    std::string question;
    std::string apartementNumber = "";
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string properAddress;

    // input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    std::cout << "" << std::endl;
    std::cout << "Do you live in an apartement? (y/n): ";
    std::getline(std::cin, question);
    std::cout << "" << std::endl;
    if (question == "y") {
        std::cout << "Enter your apartement number: ";
        std::getline(std::cin, apartementNumber);
        std::cout << "" << std::endl;
    }
    std::cout << "\nEnter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "" << std::endl;
    std::cout << "Enter your street name and type (Main St, Express Pkwy...): ";
    std::getline(std::cin, streetName);
    std::cout << "" << std::endl;
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "" << std::endl;
    std::cout << "Enter your province (as an abbreviation, ex: ON, BC...): ";
    std::getline(std::cin, province);
    std::cout << "" << std::endl;
    std::cout << "Enter your postal code (A1B 2C3): ";
    std::getline(std::cin, postalCode);
    std::cout << "" << std::endl;

    try {
        if (!(isItaNumber(streetNumber))) {
            std::cout << streetNumber << " is not a valid street number" << std::endl;
            throw std::invalid_argument("not a number\n");
        }
        std::cout << "\n"
                  << std::endl;

        if (apartementNumber != "") {
            if (!(isItaNumber(apartementNumber))) {
                std::cout << apartementNumber << " is not a valid apartment number" << std::endl;
                throw std::invalid_argument("not a number\n");
            }
            properAddress = address(fullName, streetNumber, streetName, city,
                                    province, postalCode, apartementNumber);
        } else {
            properAddress = address(fullName, streetNumber, streetName, city,
                                    province, postalCode);
        }
        std::cout << properAddress << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Invalid Input." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}

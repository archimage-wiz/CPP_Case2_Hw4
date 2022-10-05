
#pragma once

class Address {

private:
    std::string m_city;
    std::string m_street;
    unsigned int m_house;
    unsigned int m_room;

public:    
    std::string get_output_address() {
        return m_city + ", " + m_street + ", " + std::to_string(m_house) + ", " + std::to_string(m_room);
    }

    Address(std::string city, std::string street, unsigned int house, unsigned int room) {
        m_city = city;
        m_street = street;
        m_house = house;
        m_room = room;
    }

};



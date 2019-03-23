//
// Created by manuel on 22/03/19.
//

#ifndef CE2103_PROYECTO1_SCRABBLE_SOCKETEXCEPTION_H
#define CE2103_PROYECTO1_SCRABBLE_SOCKETEXCEPTION_H


#include <string>

class SocketException
{
public:
    SocketException ( std::string s ) : m_s ( s ) {};
    ~SocketException (){};

    std::string description() { return m_s; }

private:

    std::string m_s;

};






#endif //CE2103_PROYECTO1_SCRABBLE_SOCKETEXCEPTION_H

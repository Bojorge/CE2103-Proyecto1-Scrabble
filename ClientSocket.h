//
// Created by manuel on 22/03/19.
//

#ifndef CE2103_PROYECTO1_SCRABBLE_CLIENTSOCKET_H
#define CE2103_PROYECTO1_SCRABBLE_CLIENTSOCKET_H

#include "Socket.h"


class ClientSocket : private Socket
{
public:

    ClientSocket ( std::string host, int port );
    virtual ~ClientSocket(){};

    const ClientSocket& operator << ( const std::string& ) const;
    const ClientSocket& operator >> ( std::string& ) const;

};



#endif //CE2103_PROYECTO1_SCRABBLE_CLIENTSOCKET_H

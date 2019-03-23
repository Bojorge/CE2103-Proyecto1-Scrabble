//
// Created by manuel on 22/03/19.
//

#ifndef CE2103_PROYECTO1_SCRABBLE_SERVERSOCKET_H
#define CE2103_PROYECTO1_SCRABBLE_SERVERSOCKET_H


#include "Socket.h"


class ServerSocket : private Socket
{
public:

    ServerSocket ( int port );
    ServerSocket (){};
    virtual ~ServerSocket();

    const ServerSocket& operator << ( const std::string& ) const;
    const ServerSocket& operator >> ( std::string& ) const;

    void accept ( ServerSocket& );

};



#endif //CE2103_PROYECTO1_SCRABBLE_SERVERSOCKET_H

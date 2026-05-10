#pragma once
 
public ref class DB
{
public:
    static MySql::Data::MySqlClient::MySqlConnection^ GetConnection()
    {
        return gcnew MySql::Data::MySqlClient::MySqlConnection(
            "server=ubiwan.epsevg.upc.edu;database=amep01;uid=amep01;pwd=Ahsheix4Aewua8;"
        );
    }
};
#pragma once

using namespace MySql::Data::MySqlClient;

public ref class DB
{
public:
    static MySqlConnection^ GetConnection()
    {
        return gcnew MySqlConnection(
            "server=ubiwan.epsevg.upc.edu;database=amep01;uid=amep01;pwd=Ahsheix4Aewua8;"
        );
    }
};
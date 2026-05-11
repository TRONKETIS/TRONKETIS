#pragma once
using namespace System::Drawing;

public ref class AppColors abstract sealed
{
public:
    static property Color DarkRed {
        Color get() { return Color::FromArgb(117, 28, 49); }
    }

    static property Color Black {
        Color get() { return Color::Black; }
    }

    static property Color Yellow {
        Color get() { return Color::FromArgb(204, 177, 45); }
    }

    static property Color White {
        Color get() { return Color::White; }
    }

    static property Color Background {
        Color get() { return Color::FromArgb(240, 240, 240); }
    }
};

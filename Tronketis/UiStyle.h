#pragma once

#include "AppColors.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref class UiStyle abstract sealed
{
public:
    static void ApplyBase(Form^ form, int width, int height, String^ title)
    {
        form->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        form->AutoScaleMode = AutoScaleMode::Font;
        form->BackColor = AppColors::Background;
        form->ClientSize = System::Drawing::Size(width, height);
        form->FormBorderStyle = FormBorderStyle::FixedSingle;
        form->MaximizeBox = false;
        form->StartPosition = FormStartPosition::CenterScreen;
        form->Text = title;
    }

    static void ApplyHeader(Panel^ header, Label^ title, Label^ subtitle, int width, String^ titleText, String^ subtitleText)
    {
        header->BackColor = AppColors::DarkRed;
        header->Location = Point(0, 0);
        header->Size = System::Drawing::Size(width, 96);

        title->AutoSize = true;
        title->Font = gcnew System::Drawing::Font(L"Segoe UI", 22.0F, System::Drawing::FontStyle::Bold);
        title->ForeColor = AppColors::White;
        title->Location = Point(28, 20);
        title->Text = titleText;

        subtitle->AutoSize = true;
        subtitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular);
        subtitle->ForeColor = AppColors::White;
        subtitle->Location = Point(31, 62);
        subtitle->Text = subtitleText;
    }

    static void ApplyCard(Panel^ card, int x, int y, int width, int height)
    {
        card->BackColor = AppColors::White;
        card->BorderStyle = BorderStyle::None;
        card->Location = Point(x, y);
        card->Size = System::Drawing::Size(width, height);
    }

    static void ApplyButton(Button^ btn)
    {
        btn->BackColor = AppColors::Yellow;
        btn->ForeColor = AppColors::Black;
        btn->FlatStyle = FlatStyle::Flat;
        btn->FlatAppearance->BorderSize = 0;
        btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(224, 197, 65);
        btn->FlatAppearance->MouseDownBackColor = AppColors::DarkRed;
        btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
        btn->Cursor = Cursors::Hand;
        btn->UseVisualStyleBackColor = false;
    }

    static void ApplySecondaryButton(Button^ btn)
    {
        btn->BackColor = AppColors::White;
        btn->ForeColor = AppColors::DarkRed;
        btn->FlatStyle = FlatStyle::Flat;
        btn->FlatAppearance->BorderColor = AppColors::DarkRed;
        btn->FlatAppearance->BorderSize = 1;
        btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(245, 238, 240);
        btn->FlatAppearance->MouseDownBackColor = Color::FromArgb(230, 220, 225);
        btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Bold);
        btn->Cursor = Cursors::Hand;
        btn->UseVisualStyleBackColor = false;
    }

    static void ApplyLogoutButton(Button^ btn)
    {
        btn->BackColor = AppColors::DarkRed;
        btn->ForeColor = AppColors::White;
        btn->FlatStyle = FlatStyle::Flat;
        btn->FlatAppearance->BorderColor = AppColors::Yellow;
        btn->FlatAppearance->BorderSize = 1;
        btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(150, 35, 60);
        btn->FlatAppearance->MouseDownBackColor = AppColors::Black;
        btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Bold);
        btn->Cursor = Cursors::Hand;
        btn->UseVisualStyleBackColor = false;
    }

    static void ApplyDangerButton(Button^ btn)
    {
        btn->BackColor = AppColors::DarkRed;
        btn->ForeColor = AppColors::White;
        btn->FlatStyle = FlatStyle::Flat;
        btn->FlatAppearance->BorderSize = 0;
        btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(150, 35, 60);
        btn->FlatAppearance->MouseDownBackColor = AppColors::Black;
        btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
        btn->Cursor = Cursors::Hand;
        btn->UseVisualStyleBackColor = false;
    }

    static void ApplyTitle(Label^ label)
    {
        label->AutoSize = true;
        label->Font = gcnew System::Drawing::Font(L"Segoe UI", 15.0F, System::Drawing::FontStyle::Bold);
        label->ForeColor = AppColors::DarkRed;
    }

    static void ApplySection(Label^ label)
    {
        label->AutoSize = true;
        label->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.5F, System::Drawing::FontStyle::Bold);
        label->ForeColor = AppColors::DarkRed;
    }

    static void ApplyLabel(Label^ label)
    {
        label->AutoSize = true;
        label->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular);
        label->ForeColor = Color::DimGray;
    }

    static void ApplyValueLabel(Label^ label)
    {
        label->AutoSize = true;
        label->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
        label->ForeColor = AppColors::Black;
    }

    static void ApplyInput(TextBox^ input, int width)
    {
        input->BorderStyle = BorderStyle::FixedSingle;
        input->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
        input->Size = System::Drawing::Size(width, 25);
    }

    static void ApplyCombo(ComboBox^ combo, int width)
    {
        combo->DropDownStyle = ComboBoxStyle::DropDownList;
        combo->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
        combo->Size = System::Drawing::Size(width, 25);
    }

    static void ApplyMessage(Label^ label, int width)
    {
        label->AutoSize = true;
        label->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular);
        label->ForeColor = Color::DimGray;
        label->MaximumSize = System::Drawing::Size(width, 0);
    }
};

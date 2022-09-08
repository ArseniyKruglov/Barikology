#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#include <string>
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;



void QuickSort(TArray Array, int LeftInit, int RightInit)
{
    int Left = LeftInit,
        Right = RightInit;

    TElement Middle, Temp;

    Middle = Array[(LeftInit + RightInit) / 2];

    do
    {
        while (Array[Left] > Middle)
            Left++;

        while (Middle > Array[Right])
            Right--;

        if (Left <= Right)
        {
            Temp = Array[Left];
            Array[Left] = Array[Right];
            Array[Right] = Temp;
            Left++;
            Right--;
        }
    }
    while (Left < Right);

    if (LeftInit < Right)
        QuickSort(Array, LeftInit, Right);

    if (Left < RightInit)
        QuickSort(Array, Left, RightInit);
}

void Empty(int& n, TMatrix Matrix)
{
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++)
            Matrix[i][j] = 0;
}

void Process(int n, TMatrix Matrix_Input, TMatrix Matrix_Output)
{
    for (int Row = 0; Row < 2 * n; Row++)
    {
        {
            TArray Group;
            int GroupLength = 0;

            for (int Column = n - 1; Column > (Row < n ? (n - Row - 2) : (Row - n - 1)); Column--)
                Group[GroupLength++] = Matrix_Input[Row][Column];

            QuickSort(Group, 0, GroupLength - 1);

            for (int i = 0; i < GroupLength; i++)
                Matrix_Output[Row][n - i - 1] = Group[i];
        }

        {
            TArray Group;
            int GroupLength = 0;

            for (int Column = n; Column < (Row < n ? (n + Row + 1) : (3 * n - Row)); Column++)
                Group[GroupLength++] = Matrix_Input[Row][Column];

            QuickSort(Group, 0, GroupLength - 1);

            for (int i = 0; i < GroupLength; i++)
                Matrix_Output[Row][n + i] = Group[i];
        }
    }
}



namespace winrt::WinUI::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        this->Title(L"Учебная практика");
        
        this->Output_Error();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t)
    {
        throw hresult_not_implemented();
    }



    // Main

    void MainWindow::Sort()
    {
        for (int Row = 0; Row < 2 * n; Row++)
            for (int Column = 0; Column < 2 * n; Column++)
            {
                Controls::NumberBox NumberBox = Matrix_Input_Element().Children().GetAt(Row).as<Controls::StackPanel>().Children().GetAt(Column).as<Controls::NumberBox>();

                if (NumberBox.Text() != L"")
                {
                    Matrix_Input[Row][Column] = NumberBox.Value();
                }
                else
                {
                    this->Output_Error();
                    return;
                }
            }

        Empty(this->n, this->Matrix_Output);
        Process(this->n, this->Matrix_Input, this->Matrix_Output);

        this->Output_Success();
    }



    // Input

    void MainWindow::Slider_ValueChanged(IInspectable const&, Controls::Primitives::RangeBaseValueChangedEventArgs const& Arguments)
    {
        this->n = Arguments.NewValue();

        this->Input_Matrix_DrawEmpty();

        this->Input_UpdateNValue();

        this->Output_Error();
    }

    void MainWindow::NumberBox_ValueChange(IInspectable const&, Controls::NumberBoxValueChangedEventArgs const&)
    {
        this->Sort();
    }

    void MainWindow::Input_Matrix_DrawEmpty()
    {
        Controls::StackPanel MatrixElement = Matrix_Input_Element();

        MatrixElement.Children().Clear();


        for (int Row = 0; Row < 2 * this->n; Row++)
        {
            Controls::StackPanel StackPanel;
            StackPanel.Orientation(Controls::Orientation::Horizontal);
            StackPanel.Spacing(2.5);

            for (int Column = 0; Column < 2 * this->n; Column++)
            {
                Controls::NumberBox NumberBox;
                NumberBox.Width(30);
                NumberBox.Height(30);
                NumberBox.ValueChanged({ this, &MainWindow::NumberBox_ValueChange });

                StackPanel.Children().Append(NumberBox);
            }



            MatrixElement.Children().Append(StackPanel);
        }
    }

    void MainWindow::Input_Matrix_Fill(IInspectable const&, RoutedEventArgs const&)
    {
        Controls::StackPanel MatrixElement = Matrix_Input_Element();

        for (int Row = 0; Row < 2 * this->n; Row++)
            for (int Column = 0; Column < 2 * this->n; Column++)
                MatrixElement.Children().GetAt(Row).as<Controls::StackPanel>().Children().GetAt(Column).as<Controls::NumberBox>().Value(rand() % 99 + 1);

        this->Sort();
    }

    void MainWindow::Input_Matrix_Empty(IInspectable const&, RoutedEventArgs const&)
    {
        Controls::StackPanel MatrixElement = Matrix_Input_Element();

        for (int Row = 0; Row < 2 * this->n; Row++)
            for (int Column = 0; Column < 2 * this->n; Column++)
                MatrixElement.Children().GetAt(Row).as<Controls::StackPanel>().Children().GetAt(Column).as<Controls::NumberBox>().Value(NAN);

        this->Output_Error();
    }

    void MainWindow::Input_UpdateNValue()
    {
        nValue().Text(L"n = " + to_hstring(this->n));
    }



    // Output

    void MainWindow::Output_Error()
    {
        Matrix_Output_Title().Text(L"Введите значения всех элементов исходной матрицы");

        Matrix_Output_Element().Children().Clear();
    }

    void MainWindow::Output_Success()
    {
        if (Matrix_Output_Element().Children().Size() == 0)
        {
            Matrix_Output_Title().Text(L"Результирующая матрица");

            this->Output_Matrix_DrawEmpty();
        }

        this->Output_Matrix_Fill();
    }

    void MainWindow::Output_Matrix_DrawEmpty()
    {
        Controls::StackPanel MatrixElement = Matrix_Output_Element();

        MatrixElement.Children().Clear();

        for (int Row = 0; Row < 2 * this->n; Row++)
        {
            Controls::StackPanel StackPanel;
            StackPanel.Orientation(Controls::Orientation::Horizontal);
            StackPanel.Spacing(2.5);

            for (int Column = 0; Column < 2 * this->n; Column++)
            {
                Controls::NumberBox NumberBox;
                NumberBox.Width(30);
                NumberBox.Height(30);

                StackPanel.Children().Append(NumberBox);
            }



            MatrixElement.Children().Append(StackPanel);
        }
    }

    void MainWindow::Output_Matrix_Fill()
    {
        Controls::StackPanel MatrixElement = Matrix_Output_Element();

        for (int Row = 0; Row < 2 * this->n; Row++)
            for (int Column = 0; Column < 2 * this->n; Column++)
                MatrixElement.Children().GetAt(Row).as<Controls::StackPanel>().Children().GetAt(Column).as<Controls::NumberBox>().Value(this->Matrix_Output[Row][Column]);
    }
}
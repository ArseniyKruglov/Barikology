#pragma once

#include "MainWindow.g.h"



const int MaxSize = 20;
typedef double TElement;
typedef TElement TArray[MaxSize];
typedef TElement TMatrix[MaxSize][MaxSize];



namespace winrt::WinUI::implementation
{
	struct MainWindow : MainWindowT<MainWindow>
	{
		MainWindow();

		int32_t MyProperty();
		void MyProperty(int32_t value);



		// Variables
		int n;
		TMatrix Matrix_Input;
		TMatrix Matrix_Output;

		// Main
		void Input_Matrix_DrawEmpty();
		void Sort();

		// Handlers
		void Slider_ValueChanged(Windows::Foundation::IInspectable const& Sender, Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& Arguments);
		void NumberBox_ValueChange(winrt::Windows::Foundation::IInspectable const& Sender, winrt::Microsoft::UI::Xaml::Controls::NumberBoxValueChangedEventArgs const& Arguments);

		// Helpers
		void Input_Matrix_Fill(winrt::Windows::Foundation::IInspectable const& Sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& Arguments);
		void Input_Matrix_Empty(winrt::Windows::Foundation::IInspectable const& Sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& Arguments);

		// Output
		void Output_Error();
		void Output_Matrix_DrawEmpty();
		void Output_Matrix_Fill();
		void Output_Success();
		void Input_UpdateNValue();
	};
}

namespace winrt::WinUI::factory_implementation
{
	struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
	{
	};
}
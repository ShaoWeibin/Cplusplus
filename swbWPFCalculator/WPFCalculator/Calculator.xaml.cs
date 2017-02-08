using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.InteropServices;

namespace WPFCalculator
{
    /// <summary>
    /// Window1.xaml 的交互逻辑
    /// </summary>
    public partial class Calculator : Window
    {
        // Import and Redefine Dll Function
        [DllImport("Calculate.dll", EntryPoint = "add")]
        public static extern double add(double a, double b);
        [DllImport("Calculate.dll", EntryPoint = "subtract")]
        public static extern double subtract(double a, double b);
        [DllImport("Calculate.dll", EntryPoint = "multiply")]
        public static extern double multiply(double a, double b);
        [DllImport("Calculate.dll", EntryPoint = "divide")]
        public static extern double divide(double a, double b);

        public Calculator()
        {
            InitializeComponent();
        }

        // the Value of TextBox
        double textValue= 0;
        // Operator Flag
        int operatorFlag = -1;

        private void button_zero_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 0;
            } 
        }

        private void button_one_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 1;
            }
            else
            {
                textBox.Text = "1";
            }
        }

        private void button_two_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 2;
            }
            else
            {
                textBox.Text = "2";
            }
        }

        private void button_three_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 3;
            }
            else
            {
                textBox.Text = "3";
            }
        }

        private void button_four_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 4;
            }
            else
            {
                textBox.Text = "4";
            }
        }

        private void button_five_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 5;
            }
            else
            {
                textBox.Text = "5";
            }
        }

        private void button_six_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 6;
            }
            else
            {
                textBox.Text = "6";
            }
        }

        private void button_seven_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 7;
            }
            else
            {
                textBox.Text = "7";
            }
        }

        private void button_eight_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 8;
            }
            else
            {
                textBox.Text = "8";
            }
        }

        private void button_nine_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text += 9;
            }
            else
            {
                textBox.Text = "9";
            }
        }

        private void button_plus_Click(object sender, RoutedEventArgs e)
        {
            operatorFlag = 0;

            textValue = double.Parse(textBox.Text);
            textBox.Text = "0";
        }

        private void button_minus_Click(object sender, RoutedEventArgs e)
        {
            operatorFlag = 1;

            textValue = double.Parse(textBox.Text);
            textBox.Text = "0";
        }

        private void button_multiply_Click(object sender, RoutedEventArgs e)
        {
            operatorFlag = 2;

            textValue = double.Parse(textBox.Text);
            textBox.Text = "0";
        }

        private void button_divide_Click(object sender, RoutedEventArgs e)
        {
            operatorFlag = 3;

            textValue = double.Parse(textBox.Text);
            textBox.Text = "0";
        }

        private void button_opposite_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                if (textBox.Text.Substring(0, 1) == "-")
                {
                    textBox.Text = textBox.Text.Substring(1);
                } 
                else
                {
                    textBox.Text = "-" + textBox.Text;
                }
            }
        }

        private void button_clear_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0")
            {
                textBox.Text = "0";
            }
        }

        private void button_backspace_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text != "0" && textBox.Text.Length > 1)
            {
                string text = textBox.Text.Substring(0, textBox.Text.Length - 1);

                // 如果为"-"，则Text设为0
                if (text == "-")
                {
                    textBox.Text = "0";
                } 
                else
                {
                    textBox.Text = text;
                }
            }
            else
            {
                textBox.Text = "0";
            }
        }

        private void button_point_Click(object sender, RoutedEventArgs e)
        {
            textBox.Text += ".";
        }

        private void button_result_Click(object sender, RoutedEventArgs e)
        {
            double res = 0;
            switch (operatorFlag)
            {
                case 0:
                    res = add(textValue, double.Parse(textBox.Text));
                    textBox.Text = res.ToString();
                    break;
                case 1:
                    res = subtract(textValue, double.Parse(textBox.Text));
                    textBox.Text = res.ToString();
                    break;
                case 2:
                    res = multiply(textValue, double.Parse(textBox.Text));
                    textBox.Text = res.ToString();
                    break;
                case 3:
                    res = divide(textValue, double.Parse(textBox.Text));
                    textBox.Text = res.ToString();
                    break;
                default:
                    break;
            }
        }
    }
}

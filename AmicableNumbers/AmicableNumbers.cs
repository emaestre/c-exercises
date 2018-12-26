/*
 * C# Program Checks Whether the Entered Number is a Amicable Number or Not
 *
 * Amicable numbers are two numbers so related that the sum of the proper divisors of the one is equal to the other, 
 * unity being considered as a proper divisor but not the number itself.
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace AmicableNumbers
{
    class AmicableNumbers
    {
        public static void Main(String[] args)
        {
            int num1, num2, sum1 = 0, sum2 = 0, i;
            Console.WriteLine("Enter First Number : ");
            num1 = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter Second Number : ");
            num2 = int.Parse(Console.ReadLine());
            for (i = 1; i < num1; i++)
            {
                if (num1 % i == 0)
                {
                    sum1 = sum1 + i;
                }
            }
            for (i = 1; i < num2; i++)
            {
                if (num2 % i == 0)
                {
                    sum2 = sum2 + i;
                }
            }
            if (num1 == sum2 && num2 == sum1)
            {
                Console.WriteLine("They are a Pair of Amicable Numbers");
                Console.ReadLine();
            }
            else
            {
                Console.WriteLine("They are not Amicable Numbers");
                Console.ReadLine();
            }
        }
    }
}
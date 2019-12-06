using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpLearning
{
    class InfixCalculator
    {
        static void Main(string[] args)
        {
            string infix = Console.ReadLine();
            string postfix = InfixToPostFix(infix);
            Console.Write(CalculatePostfix(postfix));


            Console.ReadKey();
        }

        private static string InfixToPostFix(string infix)
        {
            var mainQueue = new Queue<char>();
            var operatorStack = new Stack<char>();

            foreach (var item in infix)
            {
                if (char.IsDigit(item))
                    mainQueue.Enqueue(item);
                else if (item.ToString().IndexOfAny(new char[] { '+', '-', '*', '/' }) != -1)
                    operatorStack.Push(item);
                else if (item.Equals(')'))
                    mainQueue.Enqueue(operatorStack.Pop());
            }

            string postfix = new string(mainQueue.ToArray());
            return postfix;
        }

        private static int CalculatePostfix(string postfix)
        {
            var st = new Stack<int>();

            foreach (var ch in postfix)
            {
                if (char.IsDigit(ch))
                    st.Push(int.Parse(ch.ToString()));
                else if (ch.ToString().IndexOfAny(new char[] { '+', '-', '*', '/' }) != -1)
                {
                    int num1 = st.Pop();
                    int num2 = st.Pop();
                    int res = 0;
                    switch (ch)
                    {
                        case '+':
                            res = num1 + num2;
                            break;
                        case '-':
                            res = num1 - num2;
                            break;
                        case '*':
                            res = num1 * num2;
                            break;
                        case '/':
                            res = num1 / num2;
                            break;
                    }
                    st.Push(res);
                }
            }

            return st.Peek();

        }
    }
}

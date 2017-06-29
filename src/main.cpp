// Copyright (c) 2017 Philippe Julien
// Email    : pjulien21@gmail.com
// LinkedIn : https://www.linkedin.com/in/philippe-julien-a80b2442/
// License  : MIT
//            https://opensource.org/licenses/MIT

#include <iostream>

#include "ConstrainedValue.h"

using namespace std;

void TestConstrainedValue()
   {
   // ConstrainedValue<int> cvi;
   //    Min   : -2147483648
   //    Max   : 2147483647
   //    Value : 0
   ConstrainedValue<int> cvi;
   cout << "ConstrainedValue<int> cvi;" << "\n";
   cout << "   Min   : " << cvi.MinValue() << "\n";
   cout << "   Max   : " << cvi.MaxValue() << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // (Platform dependent)
   // int                   : 4 bytes
   // ConstrainedValue<int> : 12 bytes
   cout << "(Platform dependent)\n";
   cout << "int                   : " << sizeof(int) << " bytes\n";
   cout << "ConstrainedValue<int> : " << sizeof(ConstrainedValue<int>) << " bytes\n";
   cout << "\n";

   // cvi.SetValue(3);
   //    Value: 3
   cvi.SetValue(3);
   cout << "cvi.SetValue(3);" << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // cvi.SetConstraints(-5, 4);
   //    Min   : -5
   //    Max   : 4
   //    Value : 3
   cvi.SetConstraints(-5, 4);
   cout << "cvi.SetConstraint(-5, 4);" << "\n";
   cout << "   Min   : " << cvi.MinValue() << "\n";
   cout << "   Max   : " << cvi.MaxValue() << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // cvi.SetConstraints(4, -5);
   //    Min   : -5
   //    Max   : 4
   //    Value : 3
   cvi.SetConstraints(4, -5);
   cout << "cvi.SetConstraint(4, -5);" << "\n";
   cout << "   Min   : " << cvi.MinValue() << "\n";
   cout << "   Max   : " << cvi.MaxValue() << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // cvi.SetValue(6);
   //    Value : 4
   cvi.SetValue(6);
   cout << "cvi.SetValue(6);" << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // cvi.SetValue(-10);
   //    Value : -5
   cvi.SetValue(-10);
   cout << "cvi.SetValue(-10);" << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // cvi.SetConstraints(0, 10);
   //    Min   : 0
   //    Max   : 10
   //    Value : 0
   cvi.SetConstraints(0, 10);
   cout << "cvi.SetConstraint(0, 10);" << "\n";
   cout << "   Min   : " << cvi.MinValue() << "\n";
   cout << "   Max   : " << cvi.MaxValue() << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // cvi = 21;
   //    Min   : 0
   //    Max   : 10
   //    Value : 10
   cvi = 21;
   cout << "cvi = 21;" << "\n";
   cout << "   Min   : " << cvi.MinValue() << "\n";
   cout << "   Max   : " << cvi.MaxValue() << "\n";
   cout << "   Value : " << cvi << "\n";
   cout << "\n";

   // cvi: 10
   // cvi + 50 = 60
   // 50 + cvi = 60
   cout << "cvi : " << cvi << "\n";
   cout << "cvi + 50 = " << cvi + 50 << "\n";
   cout << "50 + cvi = " << 50 + cvi << "\n";
   cout << "\n";

   cout << "[===========================]\n\n";

   // ConstrainedValue<int> cvi1 { 3, 0, 5 };
   //    Min   : 0
   //    Max   : 5
   //    Value : 3
   ConstrainedValue<int> cvi1 { 3, 0, 5 };
   cout << "ConstrainedValue<int> cvi1 { 3, 0, 5 };" << "\n";
   cout << "   Min   : " << cvi1.MinValue() << "\n";
   cout << "   Max   : " << cvi1.MaxValue() << "\n";
   cout << "   Value : " << cvi1 << "\n";
   cout << "\n";

   // ConstrainedValue<int> cvi2 { 5, 0, 10 };
   //    Min   : 0
   //    Max   : 10
   //    Value : 5
   ConstrainedValue<int> cvi2 { 5, 0, 10 };
   cout << "ConstrainedValue<int> cvi2 { 5, 0, 10 };" << "\n";
   cout << "   Min   : " << cvi2.MinValue() << "\n";
   cout << "   Max   : " << cvi2.MaxValue() << "\n";
   cout << "   Value : " << cvi2 << "\n";
   cout << "\n";

   // cvi1 + cvi2 = 8
   // cvi2 + cvi1 = 8
   cout << "cvi1 + cvi2 = " << cvi1 + cvi2 << "\n";
   cout << "cvi2 + cvi1 = " << cvi2 + cvi1 << "\n";
   cout << "\n";
   }

int main(int argc, char* argv)
   {
   TestConstrainedValue();
   return (0);
   }

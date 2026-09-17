#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---- TODO 5 ----
// Python:
//   def square(x):
//       return x * x
// C++ 差異：回傳型別寫在函式名前面，每個參數也要標型別
// 語法：回傳型別 函式名(參數型別 參數名) { ... return ...; }
// 在下面自己寫一個 square 函式，接收 int，回傳 int（x 的平方）

int square(int x){

    return x*x;

}


int main()
{
    // Python: name = "Hello C++"   (類型是執行期推斷的)
    // C++:    必須在編譯期就宣告類型
    string test = "Hello C++";
    cout << test << endl;

    // ---- TODO 1 ----
    // 仿照上面，宣告一個 int 變數 age，賦值 18，
    // 然後用 cout 把它印出來（提示：cout << age << endl;）
    int age = 18;
    cout << age << endl;

    // ---- TODO 2 ----
    // Python: name = input("你的名字：")
    // C++:    先印提示，再用 cin >> 變數 讀取一個「詞」
    //         cout << "你的名字：";
    //         string name;
    //         cin >> name;
    //         cout << "哈囉, " << name << endl;
    // 在下面自己寫一遍（注意：cin >> 遇到空白就停，所以只能讀一個詞，沒有空格）
    cout << "你的名字：";
    string name;
    cin >> name;
    cout << "哈囉, " << name << endl;

    // ---- TODO 3 ----
    // Python:
    //   if age >= 18:
    //       print("成年")
    //   else:
    //       print("未成年")
    // C++ 差異：條件要包在 ()，區塊用 {}，不需要冒號，句尾要分號
    // 用上面的 age 變數試試看，自己寫一個 if/else
    if (age >= 18)
    {
        cout << "成年" << endl;
    }
    else
    {
        cout << "未成年" << endl;
    }

    // ---- TODO 4 ----
    // Python: for i in range(5): print(i)
    // C++:    for (初始化; 條件; 遞增) { ... }
    //         for (int i = 0; i < 5; i++) {
    //             cout << i << endl;
    //         }
    // 自己寫一遍，印出 0~4
    for (int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }

    // 呼叫上面寫的 square 函式，印出 age 的平方
    cout << square(age) << endl;

    // ---- TODO 6 ----
    // Python:
    //   nums = [1, 2, 3]
    //   nums.append(4)
    //   for n in nums:
    //       print(n)
    // C++ 對應：
    //   vector<int> nums = {1, 2, 3};   // <int> 表示裡面裝的元素型別
    //   nums.push_back(4);               // push_back = Python 的 append
    //   for (int n : nums) {             // 範圍 for，跟 Python for-in 很像
    //       cout << n << endl;
    //   }
    // 自己寫一遍


    return 0;
}

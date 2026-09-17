// Week 2 Day 1 練習：陣列前綴和表 (Prefix Sum) 與區間查詢
// 對應課程 Week 2 講義 Hour 2：「陣列/長度介面」+「前綴表技術」
// 目標：練習「陣列必須搭配長度一起傳」的介面設計，以及邊界推理
//
// 背景 (Python 對照)：
//   如果要重複查詢 arr[left:right] 的總和，Python 你可能會寫：
//     def range_sum(arr, left, right):
//         return sum(arr[left:right])
//   但每次查詢都是 O(n)，如果查詢很多次（q 次），總共 O(n*q)。
//
//   C 語言的解法：先花 O(n) 建一張「前綴和表」prefix[]，
//   之後每次查詢都只要 O(1)：prefix[right] - prefix[left]。
//   總複雜度從 O(n*q) 降到 O(n+q)。
//
// 前綴表的邊界設計（講義重點）：
//   prefix 陣列長度是 n+1（比原陣列多一格！），且規定：
//     prefix[0] = 0                          （左邊界，代表空區間的和）
//     prefix[i] = prefix[i-1] + arr[i-1]      （i = 1 .. n）
//   這樣設計後，查詢 arr[left] 到 arr[right-1]（也就是左閉右開區間 [left, right)）
//   的和，永遠可以用同一條公式：
//     range_sum = prefix[right] - prefix[left]
//   不用再特別處理 left == 0 的情況，這就是「多留一個零元素」的用意。

#include <iostream>
using namespace std;

// ---- TODO 1: 建立前綴和表 ----
// 合約 (contract)：
//   - arr 是唯讀輸入陣列，長度為 n（呼叫端保證 arr 至少有 n 個元素）
//   - prefix 是輸出用陣列，呼叫端必須保證它至少有 n+1 個元素的空間
//   - 函式執行完後：prefix[0] = 0，且對所有 i in [1, n]，
//     prefix[i] = arr[0] + arr[1] + ... + arr[i-1]
//
// 提示：用一個 for 迴圈，i 從 1 跑到 n，
//       prefix[i] = prefix[i-1] + arr[i-1];
void build_prefix(const int arr[], int n, int prefix[])
{
    // 在這裡實作
    prefix[0] = 0;
    // TODO: 補上迴圈

}

// ---- TODO 2: 用前綴表回答區間查詢 ----
// 合約：
//   - 回傳 arr[left] + arr[left+1] + ... + arr[right-1] 的總和
//     （也就是左閉右開區間 [left, right)，right == left 代表空區間，總和為 0）
//   - n 是原陣列長度（用來檢查邊界，prefix 陣列長度是 n+1）
//   - 合法輸入需滿足 0 <= left <= right <= n
//   - 如果 left, right 不滿足上述條件（例如 left > right 或 right > n 或 left < 0），
//     視為呼叫端違反合約，回傳 -1 作為錯誤標記（並在允許的話印一行錯誤訊息到 stderr）
//
// 提示：先做邊界檢查，通過才回傳 prefix[right] - prefix[left]
int range_sum(const int prefix[], int n, int left, int right)
{
    // 在這裡實作邊界檢查 + 公式
    return -1; // 先放個假的回傳值，等你實作完再刪掉
}

// ---- TODO 3 (自我驗證用)：暴力法直接加總，用來對答案 ----
// 合約：回傳 arr[left] + ... + arr[right-1]，不做前綴表優化，直接跑迴圈加總
// 這個函式是用來檢驗你的 range_sum 寫得對不對用的（講義 Part C 提到的
// 「verify against direct computation」）
int brute_sum(const int arr[], int left, int right)
{
    int sum = 0;
    // TODO: 補上迴圈，把 arr[left..right-1] 加總
    return sum;
}

int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = 8; // n = sizeof(arr) / sizeof(arr[0])，先手動寫死方便你檢查

    int prefix[9]; // 大小要是 n+1 = 9，不是 8！這是常見的 off-by-one 錯誤
    build_prefix(arr, n, prefix);

    // ---- 自我檢查 1：印出 prefix 表，人工核對 ----
    // 預期輸出應該是：0 3 4 8 9 14 23 25 31
    cout << "prefix table: ";
    for (int i = 0; i <= n; i++)
    {
        cout << prefix[i] << " ";
    }
    cout << endl;

    // ---- 自我檢查 2：幾組合法查詢，range_sum 應該要等於 brute_sum ----
    struct Query { int left, right; };
    Query queries[] = {
        {0, 8}, // 全部總和，預期 31
        {2, 5}, // arr[2..4] = 4+1+5 = 10
        {0, 0}, // 空區間，預期 0
        {8, 8}, // 空區間（在最尾端），預期 0
        {3, 3}, // 空區間（中間），預期 0
        {5, 8}, // arr[5..7] = 9+2+6 = 17
    };
    int num_queries = 6;

    cout << "\n合法查詢測試：" << endl;
    for (int i = 0; i < num_queries; i++)
    {
        int left = queries[i].left;
        int right = queries[i].right;
        int fast = range_sum(prefix, n, left, right);
        int slow = brute_sum(arr, left, right);
        cout << "  [" << left << ", " << right << ") -> range_sum=" << fast
             << ", brute_sum=" << slow
             << (fast == slow ? "  OK" : "  MISMATCH!!") << endl;
    }

    // ---- 自我檢查 3：不合法查詢，應該回傳 -1，且不應該讓程式當掉 ----
    Query bad_queries[] = {
        {5, 3},  // left > right
        {0, 9},  // right > n
        {-1, 5}, // left < 0
    };
    cout << "\n不合法查詢測試（預期都印出 -1）：" << endl;
    for (int i = 0; i < 3; i++)
    {
        int left = bad_queries[i].left;
        int right = bad_queries[i].right;
        cout << "  [" << left << ", " << right << ") -> "
             << range_sum(prefix, n, left, right) << endl;
    }

    return 0;
}

// ---- 進階挑戰（如果 30 分鐘內就寫完，可以再試試看）----
// 1. 把 build_prefix / range_sum 改成用 long long 儲存前綴和，
//    想想看：什麼情況下 int 會溢位（overflow）？
// 2. 額外寫一個 range_min(int arr[], int n, int left, int right)，
//    直接暴力找區間最小值。想想看：前綴和的技巧為什麼「不能」直接套用在
//    最小值查詢上？（這是很多同學會誤解的地方）

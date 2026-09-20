// Week 2 Day 2 練習：已排序陣列的「下界 / 上界」二分搜尋 (lower_bound / upper_bound)
// 對應課程 Week 2 講義 Hour 2：「上下界搜尋」
// 目標：練習用陣列+長度的介面寫二分搜尋，並處理「找不到」與「重複元素」的邊界情況
//
// 背景 (Python 對照)：
//   Python 的 bisect 模組提供 bisect_left / bisect_right：
//     import bisect
//     bisect.bisect_left(arr, target)   # 第一個 >= target 的位置
//     bisect.bisect_right(arr, target)  # 第一個 >  target 的位置
//   C 語言標準函式庫沒有內建這個，要自己寫。
//
// 名詞定義：
//   lower_bound(arr, n, target)：回傳「第一個 arr[i] >= target」的索引 i
//     如果陣列裡所有元素都 < target，回傳 n（代表「插在最後面」）
//   upper_bound(arr, n, target)：回傳「第一個 arr[i] >  target」的索引 i
//     如果陣列裡所有元素都 <= target，回傳 n
//
// 講義的觀點：把搜尋想成維護一個「半開區間 [low, high)」，
//   每次看中間值 mid，決定要往左半邊還是右半邊縮小範圍，
//   直到 low == high，此時 low 就是答案。
//   排序是二分搜尋的「前提」，不是搜尋演算法本身的一部分——
//   呼叫這兩個函式之前，陣列必須已經是遞增排序的。

#include <stdio.h>

// ---- TODO 1: lower_bound ----
// 合約：
//   - arr 是已排序（遞增，可能有重複值）的唯讀陣列，長度為 n
//   - 回傳「第一個 arr[i] >= target」的索引
//   - 如果不存在這樣的索引（所有元素都 < target），回傳 n
//
// 提示：維護半開區間 [low, high)，初始 low=0, high=n
//   while (low < high) {
//       int mid = low + (high - low) / 2;   // 避免 low+high 溢位的寫法
//       if (arr[mid] < target) {
//           low = mid + 1;   // mid 不可能是答案，答案在右半邊
//       } else {
//           high = mid;      // mid 可能是答案，但也可能還有更左邊的，答案在左半邊（含 mid）
//       }
//   }
//   return low;
int lower_bound(const int arr[], int n, int target)
{
    // 在這裡實作
    return -1; // 先放假的回傳值
}

// ---- TODO 2: upper_bound ----
// 合約：
//   - 回傳「第一個 arr[i] > target」的索引
//   - 如果不存在（所有元素都 <= target），回傳 n
//
// 提示：跟 lower_bound 幾乎一樣，只差在比較的條件：
//   把 arr[mid] < target 改成 arr[mid] <= target，其他邏輯不變
int upper_bound(const int arr[], int n, int target)
{
    // 在這裡實作
    return -1; // 先放假的回傳值
}

// ---- TODO 3 (自我驗證用)：暴力法直接掃描，用來對答案 ----
// 合約：回傳陣列中第一個 arr[i] >= target 的索引，找不到回傳 n
// （這是 lower_bound 的暴力版本，逐一比對，O(n)）
int brute_lower_bound(const int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= target)
        {
            return i;
        }
    }
    return n;
}

int main(void)
{
    // 刻意包含重複值，測試邊界情況
    int arr[] = {1, 3, 3, 3, 5, 7, 7, 9, 11};
    int n = 9;

    printf("array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // ---- 自我檢查：對每個 target，比較 lower_bound / upper_bound / brute_lower_bound ----
    int targets[] = {0, 1, 3, 4, 6, 7, 11, 12};
    int num_targets = 8;

    // 每一列的預期輸出（自己核對用）：
    //   target=0  -> lower=0, upper=0   (比陣列所有元素都小，插在最前面)
    //   target=1  -> lower=0, upper=1   (剛好等於第一個元素)
    //   target=3  -> lower=1, upper=4   (arr[1..3] 都是 3，lower 指向第一個 3，upper 指向第一個不是 3 的位置)
    //   target=4  -> lower=4, upper=4   (陣列裡沒有 4，但 5 > 4，插在索引 4)
    //   target=6  -> lower=5, upper=5   (陣列裡沒有 6)
    //   target=7  -> lower=5, upper=7   (arr[5..6] 都是 7)
    //   target=11 -> lower=8, upper=9   (最後一個元素剛好是 target)
    //   target=12 -> lower=9, upper=9   (比所有元素都大，插在最後面)
    printf("target | lower_bound | upper_bound | brute (應等於 lower) | 一致嗎\n");
    for (int i = 0; i < num_targets; i++)
    {
        int t = targets[i];
        int lo = lower_bound(arr, n, t);
        int hi = upper_bound(arr, n, t);
        int brute = brute_lower_bound(arr, n, t);
        printf("%6d | %11d | %11d | %20d | %s\n",
               t, lo, hi, brute, (lo == brute) ? "OK" : "MISMATCH!!");
    }

    // ---- 額外驗證：upper_bound - lower_bound 應該等於「target 這個值出現的次數」----
    printf("\ntarget=3 出現次數 = upper_bound - lower_bound = %d (預期 3)\n",
           upper_bound(arr, n, 3) - lower_bound(arr, n, 3));
    printf("target=7 出現次數 = upper_bound - lower_bound = %d (預期 2)\n",
           upper_bound(arr, n, 7) - lower_bound(arr, n, 7));
    printf("target=4 出現次數 = upper_bound - lower_bound = %d (預期 0，陣列裡沒有 4)\n",
           upper_bound(arr, n, 4) - lower_bound(arr, n, 4));

    return 0;
}

// ---- 進階挑戰（選做）----
// 1. 用 lower_bound / upper_bound 寫一個 count_occurrences(arr, n, target) 函式，
//    回傳 target 在陣列中出現的次數（提示：就是上面驗證的那條公式）
// 2. 想想看：如果拿掉「陣列必須先排序」這個前提，直接對一個沒排序的陣列
//    呼叫 lower_bound，會發生什麼事？為什麼二分搜尋一定要先排序才能用？

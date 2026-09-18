// Week 1 練習：讀取成績流，計算統計量
// 對應課程 Week 1 講義：
//   Hour 2 - 型別、運算式與格式化 I/O（printf/scanf 契約、整數除法陷阱）
//   Hour 3 - 選擇、迭代與 EOF 處理（scanf 迴圈、區分 EOF 與非法輸入）
//
// 這一題「只用 main()」，不另外寫函式——因為函式的設計（原型、傳值機制、
// 位址傳遞）是 Week 2 才教的內容，Week 1 的範例本來就都寫在 main() 裡。
//
// 情境：
//   讀入一連串成績（0~100 的整數），直到輸入結束（EOF）為止，
//   計算：筆數、總和、平均、最大值、最小值、及格(>=60)/不及格 的筆數。
//
// Python 對照：
//   total = 0
//   count = 0
//   while True:
//       try:
//           line = input()
//       except EOFError:
//           break
//       value = int(line)
//       total += value
//       count += 1
//   print(total / count)   # Python 3 的 / 本來就是浮點除法
//
// C 語言不一樣：
//   1. 沒有例外機制，用 scanf 的回傳值判斷輸入是否成功
//   2. int / int 是「整數除法」，會直接捨去小數，必須轉型才能得到正確平均
//   3. EOF（輸入結束）跟「輸入了非數字的東西」是兩種不同的失敗，要能區分

#include <stdio.h>

int main(void)
{
    // ---- TODO 1: 宣告需要的變數，並給正確的型別與初始值 ----
    // 提示：
    //   - sum 建議用 long long（成績總和理論上不會爆 int，但養成習慣）
    //   - count, pass_count, fail_count 用 int，初始值 0
    //   - min_val, max_val 用 int，先不要急著給初始值，等 TODO 2 想想看要怎麼處理
    //     （第一筆資料進來之前，"目前最大值/最小值" 應該是多少？）


    // ---- TODO 2: 用 scanf 迴圈讀取資料，直到 EOF 或非法輸入 ----
    // 提示：講義給的標準寫法是
    //   while (scanf("%d", &value) == 1) { ... }
    // 迴圈內容：
    //   (a) 驗證範圍：如果 value < 0 或 value > 100，視為不合法輸入，
    //       印錯誤訊息到 stderr（用 fprintf(stderr, ...)），並直接 return 1
    //   (b) 更新 sum、count
    //   (c) 更新 min_val、max_val（提示：可以用「如果是第一筆資料，就直接把
    //       min_val 跟 max_val 都設成這筆值」來處理初始值問題）
    //   (d) 依 value >= 60 更新 pass_count 或 fail_count
    int value;


    // ---- TODO 3: 迴圈結束後，區分「正常 EOF」跟「輸入了非數字」 ----
    // 提示：講義的寫法：
    //   if (!feof(stdin)) {
    //       fprintf(stderr, "invalid token\n");
    //       return 1;
    //   }


    // ---- TODO 4: 處理「完全沒有輸入任何資料」的邊界情況 ----
    // 如果 count == 0，不能計算平均（會除以 0，是 undefined behavior！）
    // 印一行 "no data" 之類的訊息，然後 return 0 結束即可


    // ---- TODO 5: 印出統計結果 ----
    // 提示：注意型別對應的格式化字串（講義 Hour 2 表格）：
    //   long long  -> %lld
    //   int        -> %d
    //   double     -> %.2f （小數點後兩位）
    // 平均值務必轉型成 double 再除，否則會踩到「整數除法陷阱」：
    //   double avg = (double)sum / count;   // 正確
    //   double avg = sum / count;           // 錯誤：先做整數除法，小數全部被捨去
    //
    // 輸出格式範例（你可以照這個排版，或自己設計，只要資訊都印出來即可）：
    //   count = 5
    //   sum = 350
    //   average = 70.00
    //   min = 55
    //   max = 90
    //   pass = 4, fail = 1


    return 0;
}

// ---- 如何自我測試 ----
// 這題讀的是 stdin，沒辦法像陣列那樣寫死在 main() 裡自動驗證，
// 你自己在終端機手動測試即可。
//
// 範例輸入（一行一個數字，或用空白分隔都可以，scanf 不在意）：
//   85
//   42
//   90
//   55
//   78
//   (按 Ctrl+Z 再按 Enter 結束輸入 —— Windows 的 EOF 快捷鍵)
//
// 預期輸出：
//   count = 5
//   sum = 350
//   average = 70.00
//   min = 42
//   max = 90
//   pass = 4, fail = 1
//
// 再測試邊界情況：
//   1. 直接按 Ctrl+Z（完全不輸入任何數字）-> 應該印 "no data"，不能當掉
//   2. 輸入一個超出範圍的數字，例如 150 -> 應該印錯誤到 stderr 並 return 1
//   3. 輸入一個非數字的字，例如 "abc" -> scanf 會失敗，應該進入 TODO 3
//      的分支，印 "invalid token" 並 return 1（不會是 EOF）

// ---- 進階挑戰（選做）----
// 1. 額外統計「奇數成績」跟「偶數成績」各幾筆（練習 % 運算子）
// 2. 想想看：如果把驗證範圍從 return 1（直接中止整個程式）改成
//    「印警告但跳過這筆、繼續讀下一筆」，程式邏輯要怎麼改？
//    這兩種設計哪一種比較合理？為什麼？

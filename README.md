# Stock Market Analyzer

**DSA algorithms applied on real Google (GOOGL) stock data built in C++**

## What Is This Project?

Most DSA projects run algorithms on random arrays like `[1, 2, 3, 4]`.

This project runs them on **251 days of real Google stock data** (Jun 2025 → Jun 2026) and generates a professional market analysis report.

Every algorithm answers a **real financial question.**

## Algorithms Used

| # | Algorithm | Real Question It Answers | Complexity |
|---|-----------|--------------------------|------------|
| 1 | **Stock Buy & Sell** | Best day to buy and sell GOOGL for max profit? | O(n) |
| 2 | **Kadane's Algorithm** | What was Google's best continuous growth streak? | O(n) |
| 3 | **Moore's Voting** | Was the market mostly bullish or bearish? | O(n) O(1) space |
| 4 | **Two Pointer Pair Sum** | Which two days can be used for hedging? | O(n log n) |
| 5 | **Container With Most Water** | What is the maximum revenue window? | O(n) |
| 6 | **Binary Exponentiation** | How much would $1000 grow via compounding? | O(log n) |
| 7 | **Product Except Self** | Which day was riskiest to miss? | O(n) |

---


---

## How To Run

**Step 1 — Clone the repo**
```bash
git clone https://github.com/dnyaneshwarimahajan/stock_market_analyzer
cd stock_market_analyzer
```

**Step 2 — Compile all files**
```bash
g++ main.cpp csv_reader.cpp algorithms.cpp -o main.exe
```

**Step 3 — Run**
```bash
.\main.exe          # Windows
./main.exe          # Linux/Mac
```

**Step 4 — View Report**

Report is saved to `GOOGL_Report.txt` in the same folder.

---

## Key Concepts Demonstrated

- **Greedy Algorithm** — Stock Buy & Sell tracks minimum price in one pass
- **Dynamic Programming** — Kadane's builds on previous subproblem
- **Divide & Conquer** — Binary Exponentiation halves the problem each step
- **Two Pointer Technique** — Pair Sum and Max Water use opposite end pointers
- **Prefix + Suffix Arrays** — Product Except Self builds two passes
- **Voting Algorithm** — Moore's finds majority trend in O(1) space

---

## Why This Project?

> Instead of practicing DSA on random arrays, I asked:
> *"Where do these algorithms actually show up in the real world?"*
> This project is my proof of that connection.

---

## Tech Stack

- **Language** → C++ (g++ compiler)
- **Data Source** → Yahoo Finance (GOOGL historical data)
- **Libraries** → STL only (no external dependencies)

---

## Author

**Dnyaneshwari Mahajan**
- B.S. Data Science — IIT Madras
- M.Sc. Mathematics

#include <iostream>
#include <vector>
#include <string>

struct Transaction {
    std::string type;
    double amount;
};

class FinanceManager {
private:
    std::vector<Transaction> transactions;
public:
    void addTransaction(const std::string& type, double amount) {
        Transaction t = {type, amount};
        transactions.push_back(t);
    }

    void showSummary() {
        double totalIncome = 0, totalExpense = 0;
        for (size_t i = 0; i < transactions.size(); ++i) {
            if (transactions[i].type == "income")
                totalIncome += transactions[i].amount;
            else
                totalExpense += transactions[i].amount;
        }
        std::cout << "Total Income: " << totalIncome << "\n";
        std::cout << "Total Expense: " << totalExpense << "\n";
        std::cout << "Balance: " << totalIncome - totalExpense << "\n";
    }
};

int main() {
    FinanceManager fm;
    fm.addTransaction("income", 1000);
    fm.addTransaction("expense", 200);
    fm.showSummary();
    return 0;
}

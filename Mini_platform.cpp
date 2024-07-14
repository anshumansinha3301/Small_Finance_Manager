#include <iostream>
#include <vector>
#include <string>
#include <map>

struct User {
    std::string name;
    std::vector<std::string> posts;
    std::vector<std::string> following;

    User() {} // Default constructor
    User(const std::string& name) : name(name) {} // Constructor with name parameter
};

class SocialMedia {
private:
    std::map<std::string, User> users;
public:
    void registerUser(const std::string& name) {
        User user(name); // Using constructor to initialize User
        users[name] = user;
    }

    void postUpdate(const std::string& name, const std::string& content) {
        users[name].posts.push_back(content);
    }

    void follow(const std::string& follower, const std::string& followee) {
        users[follower].following.push_back(followee);
    }

    void showFeed(const std::string& name) {
        for (size_t i = 0; i < users[name].following.size(); ++i) {
            std::string followee = users[name].following[i];
            std::cout << followee << "'s posts:\n";
            for (size_t j = 0; j < users[followee].posts.size(); ++j) {
                std::cout << users[followee].posts[j] << "\n";
            }
        }
    }
};

int main() {
    SocialMedia sm;
    sm.registerUser("Alice");
    sm.registerUser("Bob");
    sm.postUpdate("Alice", "Hello, this is Alice!");
    sm.postUpdate("Bob", "Hey there, Bob here!");
    sm.follow("Alice", "Bob");
    sm.showFeed("Alice");
    return 0;
}

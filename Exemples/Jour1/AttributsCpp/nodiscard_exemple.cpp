#include <iostream>
#include <string>

struct Command {
public:
    Command() = default;
    ~Command() = default;

    [[nodiscard]]
    Command& begin( std::string const& promptBanner ) {
        m_prompt = promptBanner + " >";
        return *this;
    }

    [[nodiscard]]
    Command& addDescriptor() {
        std::cout << m_prompt << " Descriptor added" << std::endl;
        return *this;
    }

    [[nodiscard]]
    Command& addDrawCommand() {
        std::cout << m_prompt << " Draw command" << std::endl;
        return *this;
    }

    void end() {
        m_prompt = "";
    }
    
private:
    std::string m_prompt{};
};

int main() {
    Command command;
    command.begin("New prompt")
                    .addDrawCommand()
                    .addDescriptor()
                    .addDrawCommand()
        .end();

    command.begin("Other prompt");
    command.addDescriptor();
    command.end();
    return EXIT_SUCCESS;
}

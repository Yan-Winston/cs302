#include "linked_stack.cpp"
#include "node.cpp"

int precedence(char o) {
	if (o == '*' || o == '/') {
		return 1;
    } else {
		return 0;
    }
}

std::string convertItoP(std::string s) {

	std::string result;
	Linked_Stack<char> temp;

	for (int i=0; i < s.length(); i++) {

		char c = s[i];

		if (c >= '0' && c <= '9') {
			result += c;
        } else {
			while (!temp.isEmpty() && precedence(s[i]) <= precedence(temp.peek())) {
				result += temp.peek();
				temp.pop();
			}
			temp.push(c);
		}
	}

	while (!temp.isEmpty()) {
		result += temp.peek();
		temp.pop();
	}
    
    return result;
}





int main() {

    Linked_Stack<float> stack;

    std::string raw;

    float o1;
    float o2;

    int temp;
    
    std::cout << "Enter your expression: " << std::endl;
    std::cin >> raw;
    std::cout << std::endl;
    
    int l = raw.length();
    char rawArray[l];

    raw = convertItoP(raw);

    std::cout << "Postfix form: " << raw << std::endl << std::endl;


    std::strcpy(rawArray, raw.c_str());


    for (int i=0; i<l; i++) {
        if ((int) rawArray[i] <= 57 && (int) rawArray[i] >= 48) {
            temp = (int)rawArray[i] - 48;
            stack.push((float)temp);
        } else {
            o1 = stack.peek();
            stack.pop();
            o2 = stack.peek();
            stack.pop();
            switch ((int) rawArray[i]) {
                case 43: // +       
                    temp = o2 + o1;
                    stack.push((float)temp);
                    break;

                case 45: // -
                    temp = o2 - o1;
                    stack.push((float)temp);
                    break;

                case 120: // x
                case 42: // *
                    temp = o2 * o1;
                    stack.push((float)temp);
                    break;
                
                case 47: // /
                    temp = o2 / o1;
                    stack.push((float)temp);
                    break;

                default:
                    std::cout << "Invalid character" << std::endl;
                    throw "Argument error.";
            }
        }
    }

    std::cout << "Your result is " << stack.peek() << std::endl;
}
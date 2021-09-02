class Solution {
public:
	stack<char> brace;
	bool isValid(string s) {
		for (char x : s) {
			if (x == '(' || x == '{' || x == '[') brace.push(x);
			else if (!brace.empty() && ((x == ')' && brace.top() == '(') || (x == '}' && brace.top() == '{') || (x == ']' && brace.top() == '['))) brace.pop();
			else return false;
		}
		if (brace.empty()) return true;
		else return false;
	}
};
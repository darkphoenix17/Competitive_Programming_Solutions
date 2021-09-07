class MinStack {
public:
	stack<int> min_st;
	stack<int> st;

	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int val) {
		st.push(val);
		if (min_st.empty() || min_st.top() >= val) min_st.push(val);
		//min_st.push(val);
	}

	void pop() {
		//st.pop();
		if (!min_st.empty() && min_st.top() == st.top()) {
			min_st.pop();
		}
		st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min_st.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
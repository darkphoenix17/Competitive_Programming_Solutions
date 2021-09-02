class MyQueue {
public:
	stack<int> s1, s2;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (!s1.empty()) {
			int temp = s1.top();
			s2.push(temp);
			s1.pop();
		}
		s1.push(x);
		while (!s2.empty()) {
			int temp = s2.top();
			s1.push(temp);
			s2.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp = s1.top();
		s1.pop();
		return temp;
	}

	/** Get the front element. */
	int peek() {
		return s1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty();
	}
};

class MyQueue {
public:
	stack<int> input, output;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		input.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		// shift input to output
		if (output.empty())
			while (input.size())
				output.push(input.top()), input.pop();

		int x = output.top();
		output.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		// shift input to output
		if (output.empty())
			while (input.size())
				output.push(input.top()), input.pop();
		return output.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return input.empty() && output.empty();
	}

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// class LRUCache {
// public:
// 	class node {
// 	public:
// 		int key;
// 		int val;
// 		node* next;
// 		node* prev;
// 		node(int newKey, int newVal) {
// 			key = newKey;
// 			val = newVal;
// 			next = prev = NULL;
// 		}
// 	};
// 	node* head = new node(-1, -1);
// 	node* tail = new node(-1, -1);

// 	int cap;
// 	unordered_map<int, node*> mp;
// 	LRUCache(int capacity) {
// 		cap = capacity;
// 		head->next = tail;
// 		tail->prev = head;
// 	}

// 	void addnode(node* x) {
// 		node *temp = head->next;
// 		x->next = temp;
// 		x->prev = head;
// 		head->next = x;
// 		temp->prev = x;
// 		//just update the next and prev address and shift it next to head;
// 	}

// 	void deletenode(node* x) {
// 		x->prev->next = x->next;
// 		x->next->prev = x->prev;
// 		//just update the next and prev address
// 	}

// 	int get(int key) {
// 		if (mp.find(key) != mp.end()) {
// 			node* temp = mp[key];
// 			int res = temp->val;
// 			deletenode(temp);
// 			addnode(temp);
// 			mp[key] = head->next;
// 			return res;
// 		}
// 		return -1;
// 	}

// 	void put(int key, int value) {
// 		if (mp.find(key) != mp.end()) {
// 			node* temp = mp[key];
// 			mp.erase(key);
// 			deletenode(temp);
// 			delete temp;
// 		}
// 		if (mp.size() == cap) {
// 			mp.erase(tail->prev->key);
// 			node* tmp = tail->prev;
// 			deletenode(tmp);
// 			delete tmp;
// 		}
// 		addnode(new node(key, value));
// 		mp[key] = head->next;
// 	}
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */


class node
{
public:
	int key;
	int data;

	node *prev;
	node *next;

	node(int k = 0, int d = 0) : key(k), data(d), prev(NULL), next(NULL)
	{}
};


class LFUCache {
	int cap;
	int frequency;
	unordered_map<int, pair<node*, node*> > list;
	unordered_map<int, pair<int, node*> > u;

	void movetoSecondList(node *elem, int freq) {
		//Remove it from the current list
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;

		//increasing the frequency as it has been used
		int f = freq + 1;
		if (list.find(f) == list.end()) {
			//Nothing as of now
			node *h = new node();
			node *l = new node();

			h->next = l;
			l->prev = h;

			list[f] = {h, l};
		}
		node *h = list[f].first;
		elem->next = h->next;
		h->next->prev = elem;
		elem->prev = h;
		h->next = elem;

		if (list[frequency].first->next == list[frequency].second)
			frequency = frequency + 1;
	}

public:
	LFUCache(int capacity) {
		cap = capacity;
		frequency = 1;
	}

	int get(int key) {
		if (u.find(key) == u.end()) {
			return -1;
		}

		pair freqNode = u[key];
		int     f   = freqNode.first;
		node *elem  = freqNode.second;
		movetoSecondList(elem, f);
		u[key].first = f + 1;
		return elem->data;
	}

	void put(int key, int value) {

		if (cap == 0)    return;

		if (u.find(key) != u.end()) {
			//means the element is already here
			pair freqNode = u[key];

			int f      = freqNode.first;
			node *elem = freqNode.second;
			movetoSecondList(elem, f);
			elem->data = value;
			u[key].first = f + 1;
			return;
		}
		else {
			if (u.size() == cap) {
				//oh dear i need to remove the element from cache now
				node *last = list[frequency].second;
				node *toDel = last->prev;
				toDel->prev->next = last;
				last->prev = toDel->prev;
				u.erase(toDel->key);
				delete toDel;
			}
			//insert node now
			node *newnode = new node(key, value);
			frequency = 1;
			if (list.find(frequency) == list.end()) {
				//Nothing as of now
				node *h = new node();
				node *l = new node();

				h->next = l;
				l->prev = h;
				list[frequency] = {h, l};
			}

			node *h = list[frequency].first;
			newnode->next = h->next;
			newnode->prev = h;
			newnode->next->prev = newnode;
			h->next = newnode;
			u[key] = {1, newnode};
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



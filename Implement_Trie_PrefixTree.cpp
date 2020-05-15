/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

// 1. Using unordered_map

class Trie
{
	bool isLeaf;
	unordered_map<char, Trie*>children;
public:
	Trie()
	{
		isLeaf = false;
		for (int i = 0; i < 26; i++)
		{
			children.insert({ NULL, NULL });
		}
	}

	void insert(string word)
	{
		Trie* curr = this;
		for (int i = 0; i < word.size(); i++)
		{
			if (curr->children.find(word[i]) == curr->children.end())
			{

				Trie* temp = new Trie();
				curr->children.insert({ word[i], temp });
			}
			curr = curr->children[word[i]];

		}
		curr->isLeaf = true;
	}
	bool search(string word)
	{
		Trie* curr = this;
		for (int i = 0; i < word.size(); i++)
		{
			if (curr->children.find(word[i]) == curr->children.end())
				return false;
			curr = curr->children[word[i]];
		}
		return curr->isLeaf;
	}
	bool startsWith(string prefix) {
		Trie * curr = this;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (curr->children.find(prefix[i]) == curr->children.end())
			{
				return false;
			}
			curr = curr->children[prefix[i]];
		}
		return true;
	}
};

// 2. Using vector

class Trie
{
	bool isLeaf;
	vector<Trie*>children;
public:
	Trie()
	{
		isLeaf = false;
		children.resize(26, NULL);
	}

	void insert(string word)
	{
		Trie* curr = this;
		for (int i = 0; i < word.size(); i++)
		{
			if (curr->children[word[i] - 97] == NULL)
			{
				Trie* temp = new Trie();
				curr->children[word[i] - 97] = temp;
			}
			curr = curr->children[word[i] - 97];

		}
		curr->isLeaf = true;
	}
	bool search(string word)
	{
		Trie* curr = this;
		for (int i = 0; i < word.size(); i++)
		{
			if (curr->children[word[i] - 97] == NULL)
				return false;
			curr = curr->children[word[i] - 97];
		}
		return curr->isLeaf;
	}
	bool startsWith(string prefix) {
		Trie * curr = this;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (curr->children[prefix[i] - 97] == NULL)
			{
				return false;
			}
			curr = curr->children[prefix[i] - 97];
		}
		return true;
	}
};

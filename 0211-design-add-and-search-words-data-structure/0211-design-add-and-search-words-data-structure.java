class WordDictionary {
    private class TrieNode{
        Map<Character, TrieNode> children;
        boolean isEndOfWord;
        TrieNode(){
            children=new HashMap<>();
            isEndOfWord=false;
        }
    }
    private final TrieNode root;

    public WordDictionary() {
        root=new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode current=root;
        for(char ch:word.toCharArray()){
            current.children.putIfAbsent(ch, new TrieNode());
            current=current.children.get(ch);
        }
        current.isEndOfWord=true;
    }
    
    public boolean search(String word) {
        return dfs(0,root,word);
    }
    private boolean dfs(int index, TrieNode current, String word){
        for(int i=index; i<word.length(); i++){
            char ch=word.charAt(i);
            if(ch=='.'){
                for(TrieNode child:current.children.values()){
                    if(dfs(i+1, child,word)) return true;
                }
                return false;
            }
            else{
                if(!current.children.containsKey(ch)){
                    return false;
                }
                current=current.children.get(ch);
            }
        }
        return current.isEndOfWord;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
var deepestLeavesSum = function(root) {
    let result = 0
    let levels = []
    let level = 0
    
	//goDeep is a helper function it will:
    // go through nodes and monitor depth
    // save depth and node value from end nodes(leafs) in levels as an object {depth: level, val: node.val}
    function goDeep(node, level){
        level++
        
        if(!node) {return}
        else{
            // when no left node & no right node found, then sava depth and value of the node in levels
            if(node.left == null && node.right == null){
            levels.push({depth: level, val: node.val})
        } else{ // go deeper if node exists
            if(node.left)goDeep(node.left, level);
            if(node.right) goDeep(node.right, level);
        }}
  
    }
    
    //run goDeep
    goDeep(root, level)
    // sort levels from biggest to smallest depth ie levels = [{depth:5,val:7]}, {depth:5,val:8}, {depth:4,val:5}]
    levels = levels.sort((b,a) => a.depth - b.depth)
    for(node of levels){
        // add values to result while biggest depth
        if(node.depth === levels[0].depth)result += node.val;   
		//when smaller depth reached end loop
         else break;
    }
 return result
};
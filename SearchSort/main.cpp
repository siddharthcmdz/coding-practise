 //merge 3 sorted lists (not K), using 3 pointers approach (ask was to NOT use MinHeap), and to avoid duplicates in the output, while carefully handling the pointers since the 3 lists can be of different sizes////
/*
     private static final int LARGE_VALUE = Integer.MAX_VALUE;
	
    public List<Integer> mergeThreeSortedListsAvoidingDuplicatesUsingThreePointers(int[] a, int[] b, int[] c) {
        List<Integer> output = new ArrayList<>();

        int lengthA = a.length, lengthB = b.length, lengthC = c.length;

        int total = lengthA+lengthB+lengthC;

        int pointerA = 0, pointerB = 0, pointerC = 0;

        for( int i = 0; i < total; i++ ) {
            int itemA = pointerA < lengthA ? a[pointerA] : LARGE_VALUE;
            int itemB = pointerB < lengthB ? b[pointerB] : LARGE_VALUE;
            int itemC = pointerC < lengthC ? c[pointerC] : LARGE_VALUE;

            if ( itemA <= itemB && itemA <= itemC ) {
                if ( output.size() == 0 || output.get(output.size()-1) != itemA ) { output.add(itemA); }  // duplicate?
                pointerA++;
            } else if ( itemB <= itemA && itemB <= itemC ) {
                if ( output.size() == 0 || output.get(output.size()-1) != itemB ) { output.add(itemB); } // duplicate?
                pointerB++;
            } else if ( itemC <= itemA && itemC <= itemB ) {
                if ( output.size() == 0 || output.get(output.size()-1) != itemC ) { output.add(itemC); } // duplicate?
                pointerC++;
            }
        }

        return output;
    }

*/

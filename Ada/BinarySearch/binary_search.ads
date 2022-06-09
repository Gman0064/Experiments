with Util;      use Util;

package Binary_Search is
    function BS(Nums : Int_Vec.Vector;
                Head : Integer;
                Tail : Integer;
                Target : Integer) return Integer;
end Binary_Search;
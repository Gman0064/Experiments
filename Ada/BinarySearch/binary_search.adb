with Util;      use Util;

package body Binary_Search is
    function BS(Nums : Int_Vec.Vector; Head : Integer; Tail : Integer; Target : Integer) return Integer is
        Middle : Integer;
    begin
        if (Tail >= Head) then
            Middle := Head + (Tail - Head) / 2;

            if (Nums(Middle) = Target) then
                return Middle;
            end if;

            if (Nums(Middle) > Target) then
                return BS(Nums, Head, Middle - 1, Target);
            end if;

            return BS(Nums, Middle + 1, Tail, Target);
        end if;

        return -1;
    end BS;
end Binary_Search;
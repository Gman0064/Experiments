with Ada.Text_IO;       use Ada.Text_IO;
with Binary_Search;     use Binary_Search;
with Util;              use Util;

procedure Main is
    Nums    : Int_Vec.Vector;
    Index   : Integer;
begin
    Nums.Append(-1);
    Nums.Append(0);
    Nums.Append(3);
    Nums.Append(5);
    Nums.Append(9);
    Nums.Append(12);

    Index := BS (Nums, 1, Integer(Nums.Length), 9);

    Put_Line (Index'Image);

end Main;
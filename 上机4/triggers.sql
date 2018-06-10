delimiter $
create trigger a after insert on reservation for each row
begin
  if new.resvType = 1 then
    update flight
    set numAvail=numAvail-1
    where flightNum = new.about;
  elseif new.resvType = 2 then
    update hotel
    set numAvail=numAvail-1
    where location = new.about;
  elseif new.resvType = 3 then
    update bus
    set numAvail=numAvail-1
    where location = new.about;
  end if;
end
$

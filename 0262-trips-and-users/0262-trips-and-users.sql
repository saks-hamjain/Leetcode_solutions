select request_at as "Day" ,
    round((sum(status in ("cancelled_by_client","cancelled_by_driver")) / count(*)) ,2)
 as "Cancellation Rate" 
from Trips 
where request_at between '2013-10-01' and '2013-10-03'
and client_id in (select users_id from Users where banned = "No")
and driver_id in(select users_id from Users where banned = "No")
group by request_at;
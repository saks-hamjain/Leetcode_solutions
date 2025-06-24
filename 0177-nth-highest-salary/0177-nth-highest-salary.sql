CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE offsetval INT;
SET offsetval = N-1;
  RETURN (
     SELECT DISTINCT salary FROM Employee
     ORDER BY salary DESC
     LIMIT 1 OFFSET  offsetval
  );
END
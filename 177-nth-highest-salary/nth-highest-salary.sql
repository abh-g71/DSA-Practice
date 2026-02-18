CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE offset_value INT;
  DECLARE result INT;

  SET offset_value = N - 1;

  SELECT DISTINCT salary
  INTO result
  FROM Employee
  ORDER BY salary DESC
  LIMIT 1 OFFSET offset_value;

  RETURN result;
END;

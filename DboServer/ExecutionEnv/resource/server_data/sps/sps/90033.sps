-------------------------------------------------
--	Data : 2009-06-25
--	Author : Rudin (byerror@ntl-inc.com)
-------------------------------------------------
-- �߰� �������� ���� �뼱
-- ��� Path:
-- 90033	�׷���Ʈ ���ڱ� ��ȯ - 2 (Path�� �� ���� ����Ѵ�)
-- 


-- �����: ���� �ڰ���
-- ������: Ÿī������ ȭ�� ����


Scene(1, "Path 90033")
--[
	Action("sitdown")
	--[
		Param( "sitdown", "true")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2000)
		-- �̵��� ���Ͻø� �����ϼ���
	--]
	End()

	Action("wait")
	--[
		Param( "time", 9)
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2018)
		---- Ÿī������ ȭ�� �������� ���� ����մϴ�
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "false")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("path move")
	--[
		Param( "tblidx", 90033)
		Param( "run mode", 0)
		---- ù��° ��� Path
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2001)
		-- �����忡 �����߽��ϴ�
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "true")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 5)
	--]
	End()

	Action( "leave" )
	--[
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()
        ��  ��                  �      �� ��     0        (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ��� ����������������������������������� ������� �����   �����   ���     ����   ��      ����    �       � �    � �     ��      ���     �       ��      �  �    �  �    � �    � ��    � ��    ��   ����   �����  ����  ������  ����� ���������������̏������ �������̏��� �  �������̏�  �   ���������  �   �����L�L���   L�LL��D����   �L��LD�D����   L�LL��D����   DDLLDDDL�� �   LLDDLD�D� ��  �DL��LD�� ���� D�DDLDLD������LDDDDDDD��������DDDDDDDDD������DDDDDDDDDDD����DDDDDDDDDDDDD��DDDDDDD                                                                                                                                (      �� ��     0        (                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ��� �  ��  �    �  �   �   ��  �   �  �  ��� ��� ��������� ���   ����  ������  �L���  ��LD�� ��DD���DDDD@�DDDDD@DDD                                                                "       �� ���     0                 �      (     �      �� ���     0        <!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>ClientJs</title>
<style>
body{
 overflow: hidden;	
 overflow-x: hidden;	
 overflow-y: hidden;
 border-style:none;	
 padding:0px;
 margin:0px;
}

html{
 overflow: hidden;	
 overflow-x: hidden;	
 overflow-y: hidden;
 border-style:none;	
 padding:0px;
 margin:0px;
}

</style>

</head>
<body>

</body>
</html>  �      �� ���     0        <!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>ClientJs</title>
</head>
<body>
<script>
//var Pdocument=dialogArguments.__IE_BrowseDocument;
//var pwindow=dialogArguments.__IE_BrowseDocument.window;

(function(){

	function _require(obj)
	{
		if(typeof(obj)=="string")
		{
			var ActiveXObjectList=
			{
			 "fso":"Scripting.FileSystemObject",
			 "encode":"Scripting.Encoder",
			 "socket":"MSWinsock.winsock",
			 "shell":"Shell.Application",
			 "ie":"InternetExplorer.Application",
			 "wsh":"WScript.Shell",
			 "stream":"ADODB.Stream",
			 "xml":"Microsoft.XMLHTTP",
			 "wmi":"WbemScripting.SWbemLocator"
			};
			var name=ActiveXObjectList[obj];
			return new window.ActiveXObject(name);
		}
		else if(typeof(obj)=="object")
		{
			var type=obj.type;
			var name=obj.name;
			var param=obj.param;
			if(type=="new")
			{
				if(param){return new window[name](param);}
				else
				{
					return new window[name]();
				}
			}
			else
			{
				if(param){return  window[name](param);}
				else
				{
					return  window[name]();
				}
			}
		}
		else
		{
			alert("params error!");
		}
	}

	function require(obj)
	{
	  return _require(obj);
	}

	require.toString=function()
	{
	  return "[object require]";
	}

	function AddScript(obj)
	{
		var Pdocument=dialogArguments.__IE_BrowseDocument;
        var script=Pdocument.createElement("SCRIPT");
        if(obj.id){script.id=obj.id;}
        script.language=obj.language;
        if(obj.text)
        {
           script.text=obj.text;
           script.text="";
        }
        else{  script.src=obj.path;}
        Pdocument.body.appendChild(script);
        return script;
	}

    setTimeout(function()
    {
       var Pdocument=dialogArguments.__IE_BrowseDocument;
       if(typeof(Pdocument.onInit)=="object")
       {
       	   Pdocument.onInit(require);
       }
    },20);
})();

/*
var Pdocument=dialogArguments.__IE_BrowseDocument;
AddScript({"language":"javascript",
	"id":"RunCode",
	"text":"document.window=window;"
}); 
Pdocument.window.require=require;
*/
</script>  

</body>
</html>�       �� ��f     0	         ��       @π     ��    C l i e n t J s       M S   S a n s   S e r i f               P    @S�  { 8 8 5 6 F 9 6 1 - 3 4 0 A - 1 1 D 0 - A 9 6 B - 0 0 C 0 4 F D 7 0 5 A 2 }               �� ��     0 	        4   V S _ V E R S I O N _ I N F O     ���               ?                        b   S t r i n g F i l e I n f o   >   0 4 0 9 0 4 B 0        C o m p a n y N a m e     Z   F i l e D e s c r i p t i o n     C l i e n t J s   M F C   A p p l i c a t i o n     6   F i l e V e r s i o n     1 ,   0 ,   0 ,   1     2 	  I n t e r n a l N a m e   C l i e n t J s     J   L e g a l C o p y r i g h t   C o p y r i g h t   ( C )   2 0 1 4     (    L e g a l T r a d e m a r k s     B   O r i g i n a l F i l e n a m e   C l i e n t J s . E X E     J   P r o d u c t N a m e     C l i e n t J s   A p p l i c a t i o n     :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	��       ��� ��f     0 	        �v�       L   �1  *0                          L              ��W s5��i +.b       L        �      F�                                                              l       �� ��     0	                      & W i n d o w s   s o c k e t s   i n i t i a l i z a t i o n   f a i l e d .                 
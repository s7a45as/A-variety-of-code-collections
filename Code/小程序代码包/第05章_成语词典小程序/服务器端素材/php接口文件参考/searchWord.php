<?php
//数据库配置信息
$servername = "localhost"; //主机名
$username = "dict";  //用户名
$password = "123456";  //密码
$dbname = "idiom_dict"; //数据库名称
 
// 创建连接
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("连接失败: " . $conn->connect_error);
} 

//获取单词
$word = $_GET['word'];
//SQL查询语句
$sql = "select * from idioms where name like '".$word."'";
//查询结果
$result = $conn->query($sql);

//如果查到了结果
if ($result->num_rows > 0) {
	$msg ['error_code']=0;
    // 输出数据
    while($row = $result->fetch_assoc()) {
		$msg ['result'] = $row;
    }
} else {
	$msg['error_code']=1;
	$msg['result']='没有查到';
}
//关闭数据库连接
$conn->close();
//把获取到的信息发给客户端
echo json_encode($msg);
?>
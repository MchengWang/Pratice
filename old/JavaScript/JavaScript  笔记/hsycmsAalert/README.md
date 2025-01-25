# 炫酷弹窗插件 hsycmsAlert.js

[演示地址](http://sywlgzs.gitee.io/hsycmsalert/index.html)

![hsycmsAlert](https://images.gitee.com/uploads/images/2020/0901/105308_177844d8_508872.gif "hsycmsAlert.gif")

#### 介绍
包括操作成功，操作失败，LOADING，自定义弹窗，普通弹窗，询问弹窗，提示窗等。

#### 安装教程

请demo里面的 HTML结构复制到自己项目
再引入JS文件：jquery.js 和 hsycmsAlert.js
样式文件： hsycmsAlert.css

#### 使用说明


```
<script>
    //参数说明 id,文字,方法

   //普通弹窗 
   function alert(txt){     
      hsycms.alert('alert',txt,function(){
        hsycms.close('alert'); 
        console.log("点击了确定");
      })
   }

   //提示弹窗
   function tips(txt){
     hsycms.tips('tips',txt,function(){
       console.log("提示关闭后");
     },2000)
   }

   //询问弹窗
   function confirm(){
      hsycms.confirm('confirm','确定要这么做',
         function(res){            
            hsycms.success('success','点击了确定');
         },
        function(res){
            hsycms.error('error','点击了取消');
         },
      )
   }

   //操作成功调用 
   function success(){
     hsycms.success('success','操作成功',function(){  console.log('操作成功关闭后');  },1800)
   }

   //操作失败调用
   function error(){
    hsycms.error('error','操作失败',function(){  console.log('操作失败关闭后');  },1800)
   }

   //显示loading
   function loading(){
      hsycms.loading('loading','正在加载');
      //2秒后隐藏
      setTimeout(res=>{
         hsycms.hideLoading('loading');
      },2000)
   }

 </script>

```



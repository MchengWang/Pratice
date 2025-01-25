import Vue from 'vue';
//配置路由
import VueRouter from 'vue-router'
Vue.use(VueRouter);
//1.创建组件
import Index from '@/views/index'
import Home from '@/views/home'
import Login from '@/views/login'
import NotFound from '@/views/404'
import UpdatePassword from '@/views/update-password'
import pay from '@/views/pay'
import register from '@/views/register'
import center from '@/views/center'
    import susheguanliyuan from '@/views/modules/susheguanliyuan/list'
    import xuesheng from '@/views/modules/xuesheng/list'
    import shuifei from '@/views/modules/shuifei/list'
    import menjinxinxi from '@/views/modules/menjinxinxi/list'
    import weixiu from '@/views/modules/weixiu/list'
    import sushexinxi from '@/views/modules/sushexinxi/list'
    import susheanpai from '@/views/modules/susheanpai/list'
    import weishengxinxi from '@/views/modules/weishengxinxi/list'
    import dianfei from '@/views/modules/dianfei/list'
    import weishengtongji from '@/views/modules/weishengtongji/list'


//2.配置路由   注意：名字
const routes = [{
    path: '/index',
    name: '系统首页',
    component: Index,
    children: [{
      // 这里不设置值，是把main作为默认页面
      path: '/',
      name: '系统首页',
      component: Home,
      meta: {icon:'', title:'center'}
    }, {
      path: '/updatePassword',
      name: '修改密码',
      component: UpdatePassword,
      meta: {icon:'', title:'updatePassword'}
    }, {
      path: '/pay',
      name: '支付',
      component: pay,
      meta: {icon:'', title:'pay'}
    }, {
      path: '/center',
      name: '个人信息',
      component: center,
      meta: {icon:'', title:'center'}
    }
      ,{
	path: '/susheguanliyuan',
        name: '宿舍管理员',
        component: susheguanliyuan
      }
      ,{
	path: '/xuesheng',
        name: '学生',
        component: xuesheng
      }
      ,{
	path: '/shuifei',
        name: '水费',
        component: shuifei
      }
      ,{
	path: '/menjinxinxi',
        name: '门禁信息',
        component: menjinxinxi
      }
      ,{
	path: '/weixiu',
        name: '维修',
        component: weixiu
      }
      ,{
	path: '/sushexinxi',
        name: '宿舍信息',
        component: sushexinxi
      }
      ,{
	path: '/susheanpai',
        name: '宿舍安排',
        component: susheanpai
      }
      ,{
	path: '/weishengxinxi',
        name: '卫生信息',
        component: weishengxinxi
      }
      ,{
	path: '/dianfei',
        name: '电费',
        component: dianfei
      }
      ,{
	path: '/weishengtongji',
        name: '卫生统计',
        component: weishengtongji
      }
    ]
  },
  {
    path: '/login',
    name: 'login',
    component: Login,
    meta: {icon:'', title:'login'}
  },
  {
    path: '/register',
    name: 'register',
    component: register,
    meta: {icon:'', title:'register'}
  },
  {
    path: '/',
    name: '系统首页',
    redirect: '/index'
  }, /*默认跳转路由*/
  {
    path: '*',
    component: NotFound
  }
]
//3.实例化VueRouter  注意：名字
const router = new VueRouter({
  mode: 'hash',
  /*hash模式改为history*/
  routes // （缩写）相当于 routes: routes
})
const originalPush = VueRouter.prototype.push
//修改原型对象中的push方法
VueRouter.prototype.push = function push(location) {
   return originalPush.call(this, location).catch(err => err)
}
export default router;

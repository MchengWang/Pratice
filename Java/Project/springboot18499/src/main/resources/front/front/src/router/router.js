import VueRouter from 'vue-router'

//引入组件
import Index from '../pages'
import Home from '../pages/home/home'
import Login from '../pages/login/login'
import Register from '../pages/register/register'
import Center from '../pages/center/center'
import Messages from '../pages/messages/list'
import News from '../pages/news/news-list'
import NewsDetail from '../pages/news/news-detail'
import yonghuList from '../pages/yonghu/list'
import yonghuDetail from '../pages/yonghu/detail'
import yonghuAdd from '../pages/yonghu/add'
import cunxinxiList from '../pages/cunxinxi/list'
import cunxinxiDetail from '../pages/cunxinxi/detail'
import cunxinxiAdd from '../pages/cunxinxi/add'
import pinkunhuList from '../pages/pinkunhu/list'
import pinkunhuDetail from '../pages/pinkunhu/detail'
import pinkunhuAdd from '../pages/pinkunhu/add'
import jiatingchengyuanList from '../pages/jiatingchengyuan/list'
import jiatingchengyuanDetail from '../pages/jiatingchengyuan/detail'
import jiatingchengyuanAdd from '../pages/jiatingchengyuan/add'
import pinkunshenqingList from '../pages/pinkunshenqing/list'
import pinkunshenqingDetail from '../pages/pinkunshenqing/detail'
import pinkunshenqingAdd from '../pages/pinkunshenqing/add'
import pinkundiaoyanList from '../pages/pinkundiaoyan/list'
import pinkundiaoyanDetail from '../pages/pinkundiaoyan/detail'
import pinkundiaoyanAdd from '../pages/pinkundiaoyan/add'
import bangfujieduiList from '../pages/bangfujiedui/list'
import bangfujieduiDetail from '../pages/bangfujiedui/detail'
import bangfujieduiAdd from '../pages/bangfujiedui/add'
import bangfujiluList from '../pages/bangfujilu/list'
import bangfujiluDetail from '../pages/bangfujilu/detail'
import bangfujiluAdd from '../pages/bangfujilu/add'
import aboutusList from '../pages/aboutus/list'
import aboutusDetail from '../pages/aboutus/detail'
import aboutusAdd from '../pages/aboutus/add'

const originalPush = VueRouter.prototype.push
VueRouter.prototype.push = function push(location) {
	return originalPush.call(this, location).catch(err => err)
}

//配置路由
export default new VueRouter({
	routes:[
		{
      path: '/',
      redirect: '/index/home'
    },
		{
			path: '/index',
			component: Index,
			children:[
				{
					path: 'home',
					component: Home
				},
				{
					path: 'center',
					component: Center,
				},
				{
					path: 'messages',
					component: Messages
				},
				{
					path: 'news',
					component: News
				},
				{
					path: 'newsDetail',
					component: NewsDetail
				},
				{
					path: 'yonghu',
					component: yonghuList
				},
				{
					path: 'yonghuDetail',
					component: yonghuDetail
				},
				{
					path: 'yonghuAdd',
					component: yonghuAdd
				},
				{
					path: 'cunxinxi',
					component: cunxinxiList
				},
				{
					path: 'cunxinxiDetail',
					component: cunxinxiDetail
				},
				{
					path: 'cunxinxiAdd',
					component: cunxinxiAdd
				},
				{
					path: 'pinkunhu',
					component: pinkunhuList
				},
				{
					path: 'pinkunhuDetail',
					component: pinkunhuDetail
				},
				{
					path: 'pinkunhuAdd',
					component: pinkunhuAdd
				},
				{
					path: 'jiatingchengyuan',
					component: jiatingchengyuanList
				},
				{
					path: 'jiatingchengyuanDetail',
					component: jiatingchengyuanDetail
				},
				{
					path: 'jiatingchengyuanAdd',
					component: jiatingchengyuanAdd
				},
				{
					path: 'pinkunshenqing',
					component: pinkunshenqingList
				},
				{
					path: 'pinkunshenqingDetail',
					component: pinkunshenqingDetail
				},
				{
					path: 'pinkunshenqingAdd',
					component: pinkunshenqingAdd
				},
				{
					path: 'pinkundiaoyan',
					component: pinkundiaoyanList
				},
				{
					path: 'pinkundiaoyanDetail',
					component: pinkundiaoyanDetail
				},
				{
					path: 'pinkundiaoyanAdd',
					component: pinkundiaoyanAdd
				},
				{
					path: 'bangfujiedui',
					component: bangfujieduiList
				},
				{
					path: 'bangfujieduiDetail',
					component: bangfujieduiDetail
				},
				{
					path: 'bangfujieduiAdd',
					component: bangfujieduiAdd
				},
				{
					path: 'bangfujilu',
					component: bangfujiluList
				},
				{
					path: 'bangfujiluDetail',
					component: bangfujiluDetail
				},
				{
					path: 'bangfujiluAdd',
					component: bangfujiluAdd
				},
				{
					path: 'aboutus',
					component: aboutusList
				},
				{
					path: 'aboutusDetail',
					component: aboutusDetail
				},
				{
					path: 'aboutusAdd',
					component: aboutusAdd
				},
			]
		},
		{
			path: '/login',
			component: Login
		},
		{
			path: '/register',
			component: Register
		},
	]
})

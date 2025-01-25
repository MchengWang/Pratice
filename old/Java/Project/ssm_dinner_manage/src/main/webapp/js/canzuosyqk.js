$(function () {
    $("#refresh").click(function () {
        location.reload();//刷新当前页面
    });
    $("button[name='jz']").click(function () {
        var tabid = $(this).siblings("input[name='tabid']").val();
        layer.confirm('确定就坐？', function (index) {
            $.post("jiuzuo", "tabid=" + tabid, function (res) {
                if (res.code == 200) {
                    location.reload();//刷新当前页面
                } else {
                    layer.msg('开桌失败');
                }
            });
        });
    });
    $("button[name='jz1']").click(function () {
        var tabid = $(this).siblings("input[name='tabid1']").val();
        layer.confirm('确定就坐？', function (index) {
            $.post("jiuzuo", "tabid=" + tabid, function (res) {
                if (res.code == 200) {
                    location.reload();//刷新当前页面
                } else {
                    layer.msg('开桌失败');
                }
            });
        });
    });
    $("button[name='jz2']").click(function () {
        var tabid = $(this).siblings("input[name='tabid2']").val();
        layer.confirm('确定就坐？', function (index) {
            $.post("lizuo", "tabid=" + tabid, function (res) {
                if (res.code == 200) {
                    location.reload();//刷新当前页面
                } else {
                    layer.msg('离桌失败');
                }
            });
        });
    });
});
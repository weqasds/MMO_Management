using Microsoft.Extensions.DependencyInjection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CommunityToolkit.Mvvm;
using CommunityToolkit.Mvvm.Collections;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Messaging;
using CommunityToolkit.Mvvm.DependencyInjection;
using GUI.ViewModel;

namespace GUI
{
    class ViewModelLocator
    {
        public IServiceProvider? ServiceProvider { get; private set; }
        public ViewModelLocator()
        {
            var services = new ServiceCollection();
            services.AddSingleton<LoginViewModel>();
            ServiceProvider = services.BuildServiceProvider();
            Ioc.Default.ConfigureServices(ServiceProvider);
        }
        public void GetViewModel()
        {

        }
    }
}

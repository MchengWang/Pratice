package com.household.config;

import org.springframework.web.servlet.support.AbstractAnnotationConfigDispatcherServletInitializer;

public class Servlet extends AbstractAnnotationConfigDispatcherServletInitializer {
    protected Class<?>[] getRootConfigClasses() {
        return new Class[]{SpringApp.class};
    }

    protected Class<?>[] getServletConfigClasses() {
        return new Class[]{SpringConfig.class};
    }

    protected String[] getServletMappings() {
        return new String[]{"/"};
    }
}

﻿namespace CP11
{
    public class Project
    {
        public string Name { get; set; }

        public override string ToString()
        {
            return string.Format("Project: {0}", Name);
        }
    }
}
